#include <stdio.h>
#include <mach/mach_time.h>
#include <stdint.h>

static uint64_t freq_num = 0;
static uint64_t freq_denom = 0;

void init_clock_frequency()
{
  mach_timebase_info_data_t tb;

  if (mach_timebase_info(&tb) == KERN_SUCCESS && tb.denom != 0)
  {
    freq_num = (uint64_t)tb.numer;
    freq_denom = (uint64_t)tb.denom;
  }
}

double fib(double n, double a, double b)
{
  if (n == 0)
  {
    return a;
  }
  if (n == 1)
  {
    return b;
  }
  return fib(n - 1, b, a + b);
};

int main()
{
  init_clock_frequency();

  uint64_t start, end, time, minimum = 1000000000;
  uint16_t loop = 10000;
  double result;

  while (loop--)
  {
    start = mach_absolute_time();
    result = fib(998, 0, 1);
    end = mach_absolute_time();
    time = end - start;
    if (time < minimum)
    {
      minimum = time;
    }
  }

  minimum *= freq_num;
  minimum /= freq_denom;

  printf("took %llu ns\n", minimum);
  // Print the value to prevent clang from inlining:
  printf("%f\n", result);
}