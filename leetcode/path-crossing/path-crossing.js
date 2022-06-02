/**
 * @param {string} path
 * @return {boolean}
 */

var isPathCrossing = function (path) {
    const points = new Set();
    const directions = path.split('').map((d) => { return d; });
    
    let x = 0;
    let y = 0;
    let i = 0;
    
    const initCoord = `${x}, ${y}`;
    points.add(initCoord);
    
    while (i < directions.length) {
      
        if (directions[i] == 'N') { y++; }
        else if (directions[i] == 'W') { x--; }
        else if (directions[i] == 'S') { y--; }
        else if (directions[i] == 'E') { x++; }
        
        const coordinate = `${x}, ${y}`;
        // console.log(coordinate);
        // console.log(points);
        if (!points.has(coordinate)) {
            points.add(coordinate);
            i++;
        } else {
            return true;
        }
    }
    return false;
};
