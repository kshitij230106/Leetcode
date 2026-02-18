var createCounter = function(n){
    let current=n;

    return function(){
        let ans=current;
        current++;
        return ans;
    }
}