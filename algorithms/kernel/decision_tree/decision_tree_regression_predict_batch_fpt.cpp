/* file: decision_tree_regression_predict_batch_fpt.cpp */
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
//  Implementation of the class defining the Decision tree model
//--
*/

#include "decision_tree_regression_predict_batch.h"

namespace daal
{
namespace algorithms
{
namespace decision_tree
{
namespace regression
{
namespace prediction
{

template DAAL_EXPORT services::Status Result::allocate<DAAL_FPTYPE>(const daal::algorithms::Input *input, const daal::algorithms::Parameter *par,
                                                        const int method);

} // namespace prediction
} // namespace regression
} // namespace decision_tree
} // namespace algorithms
} // namespace daal
