class PriorityQueue {
    constructor() {
        this.data = [];
    }

    push(item) {
        this.data.push(item);
        this.data.sort((a, b) => {
            if (a.priority === b.priority) {
                if (a.time === b.time) return a.id.localeCompare(b.id);
                return a.time - b.time;
            }
            return b.priority - a.priority;
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

let Q = Number(input[0]);
let pq = new PriorityQueue();

let idx = 1;
while (Q--) {
    let parts = input[idx++].split(" ");
    let cmd = parts[0];

    if (cmd === "ADD") {
        pq.push({
            id: parts[1],
            time: Number(parts[2]),
            priority: Number(parts[3])
        });
    }
    else if (cmd === "RUN") {
        if (pq.size() === 0) console.log("EMPTY");
        else console.log(pq.pop().id);
    }
    else if (cmd === "TOP") {
        if (pq.size() === 0) console.log("EMPTY");
        else console.log(pq.top().id);
    }
    else if (cmd === "COUNT") {
        console.log(pq.size());
    }
}
