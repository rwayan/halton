## Python Binding For Halton
由于性能原因，提供了两种接口

* 使用genHalton_all(维度,长度)

可以一次性返回所有的结果，耗时比较长

Example:
```
import halton
N = 10000
DIM = 2
hg = halton.genHalton_all(DIM,N)
hn = np.array(hg, copy=False)
```

* 使用原版C++的接口
```
import halton
N = 10
h = halton.halton(True)
h.init(DIM,True,True)
for i in range(N):
    h.genHalton()
    for j in range(DIM):
        res = h.get_rnd(j+1)
        print(res)
```

-----------------------------------------------------------------------------------


## Halton

Fast Halton sequence generator. 
Generate random-start randomly permuted Halton sequence of low discrepancy numbers. 
Peak performance 10^8 numbers in 1.2 second. As a reference, 2x10^8 numbers in 1.2 second using Mersenne Twister pseudorandom number generator on the same computer (Intel i7-2630QM CPU @ 2.00GHz, DDR3 1333MHz). On a computer with larger cache and faster RAM, the performance of Halton will be closer to Mersenne Twister.

To compile, use C++ 17 compatible compiler with -O2 switch.

TODO: Follow C++ 17 standard and remove dimension limitation.

## References:

Ökten, G., Generalized von Neumann-Kakutani transformation and random-start scrambled Halton sequences. Journal of Complexity, 2009, Vol 25, No 4, 318--331.<br />
Ökten, G., Shah, M. and Goncharov, Y., Random and deterministic digit permutations of the Halton sequence. Monte Carlo and Quasi-Monte Carlo Methods, Springer, 2010, 609-622.<br />
Xu, L., & Ökten, G., High-performance financial simulation using randomized quasi-Monte Carlo methods. Quantitative Finance, 2015, Vol 15, No 8, 1425-1436.
