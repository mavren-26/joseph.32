function fractionalKnapsack(values, weights, W){
    let items = values.map((v,i)=>[v/weights[i], v, weights[i]]);
    items.sort((a,b)=>b[0]-a[0]);
    let total = 0;
    for(let [ratio,v,w] of items){
        if(W == 0) break;
        let take = Math.min(w, W);
        total += take * v / w;
        W -= take;
    }
    return total;
}

// Driver code
let values = [60,100,120];
let weights = [10,20,30];
let W = 50;
console.log("Maximum value:", fractionalKnapsack(values, weights, W));
