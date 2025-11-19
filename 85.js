function activitySelection(start, end){
    let activities = start.map((s,i)=>[s,end[i]]);
    activities.sort((a,b)=>a[1]-b[1]);
    let count = 0, last_end = -1;
    for(let [s,e] of activities){
        if(s >= last_end){
            count++;
            last_end = e;
        }
    }
    return count;
}

// Driver code
let start = [1,3,0,5,8,5];
let end = [2,4,6,7,9,9];
console.log("Maximum activities:", activitySelection(start, end));
