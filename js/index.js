const fib = (n, a = 0, b = 1) => {
  if (n == 0) {
    return a;
  }
  if (n == 1) {
    return b;
  }
  return fib(n - 1, b, a + b);
};

let loops = 10000;
let minimum = Infinity;

while (loops--) {
  const start = performance.now();
  fib(998);
  const end = performance.now();
  minimum = Math.min(minimum, end - start);
}

const nanoseconds = minimum * 1000 * 1000;

console.log(`Took ${nanoseconds}ns`);
