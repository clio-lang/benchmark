package main

import (
	"fmt"
	"math"
	"time"
)

func fib(n, a, b int) {
	if n == 0 {
		return
	}

	if n == 1 {
		return
	}

	fib(n-1, b, a+b)

}

func main() {
	loops := 10_000
	minimum := int64(math.MaxInt64)

	for loops >= 0 {
		start := time.Now()
		fib(998, 0, 1)

		elapsed := int64(time.Since(start).Nanoseconds())
		if elapsed < minimum {
			minimum = elapsed
		}
		loops--
	}

	fmt.Printf("Took %dns", minimum)
}
