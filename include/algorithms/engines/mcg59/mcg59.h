/* file: mcg59.h */
/*******************************************************************************
* Copyright 2014-2018 Intel Corporation.
*
* This software and the related documents are Intel copyrighted  materials,  and
* your use of  them is  governed by the  express license  under which  they were
* provided to you (License).  Unless the License provides otherwise, you may not
* use, modify, copy, publish, distribute,  disclose or transmit this software or
* the related documents without Intel's prior written permission.
*
* This software and the related documents  are provided as  is,  with no express
* or implied  warranties,  other  than those  that are  expressly stated  in the
* License.
*******************************************************************************/

/*
//++
//  Implementation of the Mersenne Twister engine in the batch processing mode
//--
*/

#ifndef __MCG59_H__
#define __MCG59_H__

#include "algorithms/engines/mcg59/mcg59_types.h"
#include "algorithms/engines/engine.h"

namespace daal
{
namespace algorithms
{
namespace engines
{
namespace mcg59
{
/**
 * @defgroup engines_mcg59_batch Batch
 * @ingroup engines_mcg59
 * @{
 */
namespace interface1
{
/**
 * <a name="DAAL-CLASS-ALGORITHMS__ENGINES__MCG59__BATCHCONTAINER"></a>
 * \brief Provides methods to run implementations of the mcg59 engine.
 *        This class is associated with the \ref mcg59::interface1::Batch "mcg59::Batch" class
 *        and supports the method of mcg59 engine computation in the batch processing mode
 *
 * \tparam algorithmFPType  Data type to use in intermediate computations of mcg59 engine, double or float
 * \tparam method           Computation method of the engine, mcg59::Method
 * \tparam cpu              Version of the cpu-specific implementation of the engine, daal::CpuType
 */
template<typename algorithmFPType, Method method, CpuType cpu>
class DAAL_EXPORT BatchContainer : public daal::algorithms::AnalysisContainerIface<batch>
{
public:
    /**
     * Constructs a container for the mcg59 engine with a specified environment
     * in the batch processing mode
     * \param[in] daalEnv   Environment object
     */
    BatchContainer(daal::services::Environment::env *daalEnv);
    ~BatchContainer();
    /**
     * Computes the result of the mcg59 engine in the batch processing mode
     *
     * \return Status of computations
     */
    services::Status compute() DAAL_C11_OVERRIDE;
};

/**
 * <a name="DAAL-CLASS-ALGORITHMS__ENGINES__MCG59__BATCH"></a>
 * \brief Provides methods for mcg59 engine computations in the batch processing mode
 *
 * \tparam algorithmFPType  Data type to use in intermediate computations of mcg59 engine, double or float
 * \tparam method           Computation method of the engine, mcg59::Method
 *
 * \par Enumerations
 *      - mcg59::Method          Computation methods for the mcg59 engine
 *
 * \par References
 *      - \ref engines::interface1::Input  "engines::Input" class
 *      - \ref engines::interface1::Result "engines::Result" class
 */
template<typename algorithmFPType = DAAL_ALGORITHM_FP_TYPE, Method method = defaultDense>
class DAAL_EXPORT Batch : public engines::BatchBase
{
public:
    typedef engines::BatchBase super;

    typedef typename super::InputType  InputType;
    typedef typename super::ResultType ResultType;

    /**
     * Creates mcg59 engine
     * \param[in] seed  Initial condition for mcg59 engine
     *
     * \return Pointer to mcg59 engine
     */
    static services::SharedPtr<Batch<algorithmFPType, method> > create(size_t seed = 777);

    /**
     * Returns method of the engine
     * \return Method of the engine
     */
    virtual int getMethod() const DAAL_C11_OVERRIDE { return (int)method; }

    /**
     * Returns the structure that contains results of mcg59 engine
     * \return Structure that contains results of mcg59 engine
     */
    ResultPtr getResult() { return _result; }

    /**
     * Registers user-allocated memory to store results of mcg59 engine
     * \param[in] result  Structure to store results of mcg59 engine
     *
     * \return Status of computations
     */
    services::Status setResult(const ResultPtr& result)
    {
        DAAL_CHECK(result, services::ErrorNullResult)
        _result = result;
        _res = _result.get();
        return services::Status();
    }

    /**
     * Returns a pointer to the newly allocated mcg59 engine
     * with a copy of input objects and parameters of this mcg59 engine
     * \return Pointer to the newly allocated engine
     */
    services::SharedPtr<Batch<algorithmFPType, method> > clone() const
    {
        return services::SharedPtr<Batch<algorithmFPType, method> >(cloneImpl());
    }

    /**
     * Allocates memory to store the result of the mcg59 engine
     *
     * \return Status of computations
     */
    virtual services::Status allocateResult() DAAL_C11_OVERRIDE
    {
        services::Status s = this->_result->template allocate<algorithmFPType>(&(this->input), NULL, (int) method);
        this->_res = this->_result.get();
        return s;
    }

protected:
    Batch(size_t seed = 777)
    {
        initialize();
    }

    Batch(const Batch<algorithmFPType, method> &other): super(other)
    {
        initialize();
    }

    virtual Batch<algorithmFPType, method> *cloneImpl() const DAAL_C11_OVERRIDE
    {
        return new Batch<algorithmFPType, method>(*this);
    }

    void initialize()
    {
        Analysis<batch>::_ac = new __DAAL_ALGORITHM_CONTAINER(batch, BatchContainer, algorithmFPType, method)(&_env);
        _in = &input;
        _result.reset(new ResultType());
    }

private:
    ResultPtr _result;
};
typedef services::SharedPtr<Batch<> > mcg59Ptr;
typedef services::SharedPtr<const Batch<> > mcg59ConstPtr;

} // namespace interface1
using interface1::BatchContainer;
using interface1::Batch;
using interface1::mcg59Ptr;
using interface1::mcg59ConstPtr;
/** @} */
} // namespace mcg59
} // namespace engines
} // namespace algorithms
} // namespace daal
#endif
