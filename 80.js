// task_scheduler.js
class MaxHeap {
  constructor() {
    this.data = [];
  }
  size(){ return this.data.length; }
  push(val){
    this.data.push(val);
    this._siftUp(this.data.length - 1);
  }
  pop(){
    if (this.data.length === 0) return undefined;
    const top = this.data[0];
    const last = this.data.pop();
    if (this.data.length) {
      this.data[0] = last;
      this._siftDown(0);
    }
    return top;
  }
  _siftUp(i){
    while (i > 0) {
      const p = Math.floor((i-1)/2);
      if (this.data[i] > this.data[p]) {
        [this.data[i], this.data[p]] = [this.data[p], this.data[i]];
        i = p;
      } else break;
    }
  }
  _siftDown(i){
    const n = this.data.length;
    while (true) {
      let largest = i;
      const l = 2*i + 1, r = 2*i + 2;
      if (l < n && this.data[l] > this.data[largest]) largest = l;
      if (r < n && this.data[r] > this.data[largest]) largest = r;
      if (largest !== i) {
        [this.data[i], this.data[largest]] = [this.data[largest], this.data[i]];
        i = largest;
      } else break;
    }
  }
}

function leastInterval(tasks, n) {
  if (n === 0) return tasks.length;
  const freq = new Map();
  for (const t of tasks) freq.set(t, (freq.get(t) || 0) + 1);
  const heap = new MaxHeap();
  for (const c of freq.values()) heap.push(c);

  let time = 0;
  while (heap.size()) {
    const temp = [];
    let k = n + 1;
    for (let i = 0; i < k; ++i) {
      if (heap.size()) {
        let top = heap.pop();
        top -= 1;
        if (top > 0) temp.push(top);
        time += 1;
      } else {
        if (temp.length) time += 1;
        else break;
      }
    }
    for (const x of temp) heap.push(x);
  }
  return time;
}

// Driver
const tests = [
  {tasks: ["A","A","A","B","B","B"], n:2, expect:8},
  {tasks: ["A","A","A","B","B","B"], n:0, expect:6},
  {tasks: ["A","A","A","A","A","A","B","C","D","E","F","G"], n:2, expect:16}
];

for (const t of tests) {
  const out = leastInterval(t.tasks, t.n);
  console.log("tasks:", t.tasks.join(''), "n:", t.n, "->", out, "expected:", t.expect);
}
console.log("JS Task Scheduler tests done.");
