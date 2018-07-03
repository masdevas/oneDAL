/* file: ResultId.java */
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
 * @ingroup minmax
 * @{
 */
package com.intel.daal.algorithms.normalization.minmax;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NORMALIZATION__MINMAX__RESULTID"></a>
 * \brief Available identifiers of results of the Min-max normalization algorithm
 */
public final class ResultId {
    /** @private */
    static {
        System.loadLibrary("JavaAPI");
    }

    private int _value;

    /**
     * Constructs the result object identifier using the provided value
     * @param value     Value corresponding to the result object identifier
     */
    public ResultId(int value) {
        _value = value;
    }

    /**
     * Returns the value corresponding to the result object identifier
     * @return Value corresponding to the result object identifier
     */
    public int getValue() {
        return _value;
    }

    private static final int normalizedDataId = 0;
    public static final ResultId normalizedData = new ResultId(normalizedDataId); /*!< Table to store the result */
}
/** @} */
