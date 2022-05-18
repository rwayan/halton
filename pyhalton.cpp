#include "halton.h"
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"
#include "pybind11/numpy.h"


using namespace pybind11;
namespace py = pybind11;


// -------------
// pure C++ code
// -------------

std::vector<std::vector<double>> c_genHalton_all(size_t dim, size_t seqLength)
{
	std::vector<std::vector<double>> output;
	output.resize(dim, std::vector<double>(seqLength));

	std::shared_ptr<halton> p(new halton());

	p->init(dim, true, true); // DIM dimensions, random start, randomly permuted
	//printf("Running...\n");

	for (size_t i = 0; i < seqLength; i++)
	{
		//Generate the ith vector in the halton sequence, the (i-1)th vector will be discarded
		p->genHalton();
		//pmt->genrand64_real3();
		for(size_t j = 0; j < dim; j++)
		{
		//Use the jth dimension of the ith vector
			output[j][i] = p->get_rnd(j + 1);		
		}
	}
	return output;
}



// ----------------
// Python interface
// ----------------

// wrap C++ function with NumPy array IO
std::vector<std::vector<double>> genHalton_all(size_t dim, size_t seqLength)
{
	// call pure C++ function
	std::vector<std::vector<double>> result_vec = c_genHalton_all(dim, seqLength);
	return result_vec;
}


PYBIND11_MODULE(halton, m) {
	m.def("genHalton_all", &genHalton_all, return_value_policy::take_ownership);
}