/* file: split_layer_forward_batch_container.h */
/*******************************************************************************
* Copyright 2014-2019 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/*
//++
//  Implementation of split layer container.
//--
*/

#ifndef __SPLIT_LAYER_FORWARD_BATCH_CONTAINER_H__
#define __SPLIT_LAYER_FORWARD_BATCH_CONTAINER_H__

#include "neural_networks/layers/split/split_layer.h"
#include "split_layer_forward_kernel.h"
#include "service_numeric_table.h"

using namespace daal::internal;

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace split
{
namespace forward
{
namespace interface1
{
template<typename algorithmFPType, Method method, CpuType cpu>
BatchContainer<algorithmFPType, method, cpu>::BatchContainer(daal::services::Environment::env *daalEnv)
{
    __DAAL_INITIALIZE_KERNELS(internal::SplitKernel, algorithmFPType, method);
}

template<typename algorithmFPType, Method method, CpuType cpu>
BatchContainer<algorithmFPType, method, cpu>::~BatchContainer()
{
    __DAAL_DEINITIALIZE_KERNELS();
}

template<typename algorithmFPType, Method method, CpuType cpu>
services::Status BatchContainer<algorithmFPType, method, cpu>::compute()
{
    split::forward::Input *input = static_cast<split::forward::Input *>(_in);
    split::forward::Result *result = static_cast<split::forward::Result *>(_res);

    split::Parameter *parameter = static_cast<split::Parameter *>(_par);
    daal::services::Environment::env &env = *_env;

    Tensor *inputTensor = input->get(layers::forward::data).get();
    const size_t nOutputs = parameter->nOutputs;

    TArray<Tensor *, cpu> resultBlock(nOutputs);
    Tensor **resultTensors = resultBlock.get();
    DAAL_CHECK_MALLOC(resultTensors);

    for(size_t i = 0; i < nOutputs; i++)
    {
        resultTensors[i] = result->get(valueCollection, i).get();
    }

    __DAAL_CALL_KERNEL(env, internal::SplitKernel, __DAAL_KERNEL_ARGUMENTS(algorithmFPType, method), compute, inputTensor, resultTensors, nOutputs);
}
} // namespace interface1
} // namespace forward

} // namespace split
} // namespace layers
} // namespace neural_networks
} // namespace algorithms
} // namespace daal

#endif
