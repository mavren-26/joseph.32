class PriorityQueue {
    constructor() {
        this.data = [];
    }

    push(item) {
        this.data.push(item);
        this.data.sort((a, b) => {
            if (a.severity === b.severity) return a.order - b.order;
            return b.severity - a.severity;
        });
    }

    pop() {
        return this.data.shift();
    }

    top() {
        return this.data[0];
    }

    size() {
        return this.data.length;
    }
}

const fs = require("fs");
const input = fs.readFileSync(0, "utf-8").trim().split("\n");

let N = Number(input[0]);
let pq = new PriorityQueue();
let arrival = 0;

let idx = 1;
while (N--) {
    let parts = input[idx++].split(" ");
    let cmd = parts[0];

    if (cmd === "ADD") {
        pq.push({ name: parts[1], severity: Number(parts[2]), order: arrival++ });
    }
    else if (cmd === "TREAT") {
        if (pq.size() === 0) console.log("EMPTY");
        else console.log(pq.pop().name);
    }
    else if (cmd === "PEEK") {
        if (pq.size() === 0) console.log("EMPTY");
        else console.log(pq.top().name);
    }
    else if (cmd === "SIZE") {
        console.log(pq.size());
    }
}
