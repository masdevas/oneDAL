/* file: logistic_cross_layer_forward_impl.i */
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
//  Implementation of the forward logistic cross layer
//--
*/

#ifndef __LOGISTIC_CROSS_LAYER_FORWARD_IMPL_I__
#define __LOGISTIC_CROSS_LAYER_FORWARD_IMPL_I__

using namespace daal::internal;
using namespace daal::services;

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace loss
{
namespace logistic_cross
{
namespace forward
{
namespace internal
{

template<typename algorithmFPType, Method method, CpuType cpu>
services::Status LogisticCrossKernel<algorithmFPType, method, cpu>::compute(const Tensor &inputTensor, const Tensor &groundTruthTensor, Tensor &resultTensor)
{
    size_t nRowsToProcess = inputTensor.getDimensionSize(0);
    TArray<algorithmFPType, cpu> sPtr(nRowsToProcess);
    algorithmFPType *s = sPtr.get();

    ReadSubtensor<algorithmFPType, cpu, Tensor> inputBlock(const_cast<Tensor&>(inputTensor), 0, 0, 0, nRowsToProcess);
    DAAL_CHECK_BLOCK_STATUS(inputBlock);
    const algorithmFPType *inputArray = inputBlock.get();

    ReadSubtensor<algorithmFPType, cpu, Tensor> groundTruthBlock(const_cast<Tensor&>(groundTruthTensor), 0, 0, 0, nRowsToProcess);
    DAAL_CHECK_BLOCK_STATUS(groundTruthBlock);
    const algorithmFPType *groundTruthArray = groundTruthBlock.get();

    WriteSubtensor<algorithmFPType, cpu, Tensor> resultBlock(resultTensor, 0, 0, 0, nRowsToProcess);
    DAAL_CHECK_BLOCK_STATUS(resultBlock);
    algorithmFPType &loss = resultBlock.get()[0];

    size_t nDataElements = inputBlock.getSize();
    for(size_t i = 0; i < nDataElements; i++)
    {
        if(inputArray[i] >= (algorithmFPType)0)
        {
            s[i] = -inputArray[i];
        }
        else
        {
            s[i] = inputArray[i];
        }
    }
    Math<algorithmFPType, cpu>::vExp(nDataElements, s, s);
    for(size_t i = 0; i < nDataElements; i++)
    {
        s[i] += 1.0;
    }
    Math<algorithmFPType, cpu>::vLog(nDataElements, s, s);
    for(size_t i = 0; i < nDataElements; i++)
    {
        s[i] = inputArray[i] * ((inputArray[i] > 0) - groundTruthArray[i]) + s[i];
    }

    loss = 0;
    for(size_t i = 0; i < nDataElements; i++)
    {
        loss += s[i];
    }
    loss = loss / nRowsToProcess;
    return services::Status();
}

} // namespace internal
} // namespace forward
} // namespace logistic_cross
} // namespace loss
} // namespace layers
} // namespace neural_networks
} // namespace algorithms
} // namespace daal

#endif
