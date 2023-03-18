/**
 * @param {string} s
 * @return {string}
 */

var reverseOnlyLetters = function(s) {
    
    let initArr = s.split('')
    let left = 0
    let right = initArr.length - 1
    
    function isLetter(char) {
        return /^[a-zA-Z]$/.test(char);
    }
   
    while (left < right) {
        
        while(left < right && isLetter(initArr[left]) === false) { left ++ }
        while(left < right && isLetter(initArr[right]) === false) { right-- }
        if (left >= right) break;
        
        let temp = initArr[left]
        initArr[left] = initArr[right]
        initArr[right] = temp
        left++
        right--
    }
    
    return initArr.join('')
};