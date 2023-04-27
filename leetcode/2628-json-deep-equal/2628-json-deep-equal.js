/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
function areDeeplyEqual(o1, o2) {
    if (o1 === o2) return true;
    if (o1 === null || o2 === null) return false;
    if (typeof o1 !== 'object' || typeof o2 !== 'object') return false;
    if (Array.isArray(o1) !== Array.isArray(o2)) return false;
    
    const keys1 = Object.keys(o1);
    const keys2 = Object.keys(o2);
    
    if (keys1.length !== keys2.length)  return false;
    return keys1.every(key => keys2.includes(key) && areDeeplyEqual(o1[key], o2[key]));

}