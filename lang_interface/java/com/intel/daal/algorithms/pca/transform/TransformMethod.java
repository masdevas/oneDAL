/* file: TransformMethod.java */
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
 * @ingroup pca_transform
 * @{
 */
package com.intel.daal.algorithms.pca.transform;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__PCA__TRANSFORM__METHOD"></a>
 * @brief Available methods for PCA transformation
 */
public final class TransformMethod {
    /** @private */
    static {
        System.loadLibrary("JavaAPI");
    }

    private int _value;

    /**
     * Constructs the method object using the provided value
     * @param value     Value corresponding to the method object
     */
    public TransformMethod(int value) {
        _value = value;
    }

    /**
     * Returns the value corresponding to the method object
     * @return Value corresponding to the method object
     */
    public int getValue() {
        return _value;
    }

    private static final int DefaultDense = 0;
    public static final TransformMethod defaultDense = new TransformMethod(DefaultDense); /*!< Default: performance-oriented method.
                                                                          Works with all types  of input numeric tables */
}
/** @} */
