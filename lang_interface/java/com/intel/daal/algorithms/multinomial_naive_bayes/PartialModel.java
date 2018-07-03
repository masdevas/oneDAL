/* file: PartialModel.java */
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

/**
 * @ingroup multinomial_naive_bayes
 * @{
 */
package com.intel.daal.algorithms.multinomial_naive_bayes;

import com.intel.daal.data_management.data.Factory;
import com.intel.daal.data_management.data.NumericTable;
import com.intel.daal.services.DaalContext;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__MULTINOMIAL_NAIVE_BAYES__PARTIALMODEL"></a>
 * @brief Multinomial naive Bayes PartialModel
 */
public class PartialModel extends com.intel.daal.algorithms.classifier.Model {
    /** @private */
    static {
        System.loadLibrary("JavaAPI");
    }

    public PartialModel(DaalContext context, long cModel) {
        super(context, cModel);
    }

    /**
     * Returns Numeric Table containing group sums with class label used as an index
     *  @return Numeric Table containing group sums with class label used as an index
     */
    public NumericTable getClassGroupSum() {
        return (NumericTable)Factory.instance().createObject(getContext(), cGetClassGroupSum(this.getCObject()));
    }

    /**
     * Returns Numeric Table containing sum of all observations and features for each class
     *  @return Numeric Table containing sum of all observations and features for each class
     */
    public NumericTable getClassSize() {
        return (NumericTable)Factory.instance().createObject(getContext(), cGetClassSize(this.getCObject()));
    }

    /**
     * Returns number of features in training dataset
     *  @return Number of features in training dataset
     */
    public long getNFeatures() {
        return cGetNFeatures(this.getCObject());
    }

    /**
     * Returns number of observations in training dataset
     *  @return Number of observations in training dataset
     */
    public long getNObservations() {
        return cGetNObservations(this.getCObject());
    }

    private native long cGetClassGroupSum(long modelAddr);

    private native long cGetClassSize(long modelAddr);

    private native long cGetNFeatures(long modelAddr);

    private native long cGetNObservations(long modelAddr);
}
/** @} */
