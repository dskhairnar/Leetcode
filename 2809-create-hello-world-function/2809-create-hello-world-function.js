/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return function(...args) {
        return "Hello World";  // Return the desired string
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */
