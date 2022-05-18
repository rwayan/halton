import halton
N = 100000000

import numpy as np
import datetime

start = datetime.datetime.now()
b = halton.genHalton_all(2,N)
end = datetime.datetime.now()
print(end - start)
start = datetime.datetime.now()
x = np.array(b, copy=False)
end = datetime.datetime.now()
print(end - start)




import timeit

import_module = '''
import halton
N = 1000

'''

testcode = '''
b = halton.genHalton_all(2,N)
'''

print(timeit.timeit(stmt=testcode, setup=import_module,number=1000))

