// top_k_frequent.js
class MinHeap {
  constructor(compare) {
    this.data = [];
    this.compare = compare || ((a,b) => a - b);
  }
  size() { return this.data.length; }
  peek() { return this.data[0]; }
  push(val) {
    this.data.push(val);
    this._siftUp(this.data.length - 1);
  }
  pop() {
    if (this.data.length === 0) return undefined;
    const top = this.data[0];
    const last = this.data.pop();
    if (this.data.length > 0) {
      this.data[0] = last;
      this._siftDown(0);
    }
    return top;
  }
  _siftUp(i) {
    while (i > 0) {
      const p = Math.floor((i - 1) / 2);
      if (this.compare(this.data[i], this.data[p]) < 0) {
        [this.data[i], this.data[p]] = [this.data[p], this.data[i]];
        i = p;
      } else break;
    }
  }
  _siftDown(i) {
    const n = this.data.length;
    while (true) {
      let smallest = i;
      const l = 2 * i + 1, r = 2 * i + 2;
      if (l < n && this.compare(this.data[l], this.data[smallest]) < 0) smallest = l;
      if (r < n && this.compare(this.data[r], this.data[smallest]) < 0) smallest = r;
      if (smallest !== i) {
        [this.data[i], this.data[smallest]] = [this.data[smallest], this.data[i]];
        i = smallest;
      } else break;
    }
  }
}

function topKFrequent(nums, k) {
  const freq = new Map();
  for (const x of nums) freq.set(x, (freq.get(x) || 0) + 1);

  // min-heap by frequency
  const heap = new MinHeap((a,b) => a[0] - b[0]); // a = [freq, num]
  for (const [num, f] of freq.entries()) {
    heap.push([f, num]);
    if (heap.size() > k) heap.pop();
  }
  const res = [];
  while (heap.size()) res.push(heap.pop()[1]);
  return res;
}

// driver
const tests = [
  {nums: [1,1,1,2,2,3], k:2},
  {nums: [1], k:1},
  {nums: [4,4,4,6,6,7,7,7,7], k:1}
];

for (const t of tests) {
  console.log("nums:", t.nums, "k:", t.k, "->", topKFrequent(t.nums, t.k));
}
console.log("JS tests done.");
