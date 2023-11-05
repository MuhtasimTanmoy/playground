String.prototype.replicate = function(times) {
    let res = "";
    while (times-- > 0)
        res += this.valueOf();
    return res;
}