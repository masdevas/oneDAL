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
 * @ingroup pivoted_qr
 * @{
 */
package com.intel.daal.algorithms.pivoted_qr;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__PIVOTED_QR__RESULTID"></a>
 * @brief Available types of the results of the pivoted QR algorithm
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

    private static final int matrixQId           = 0;
    private static final int matrixRId           = 1;
    private static final int permutationMatrixId = 2;

    public static final ResultId matrixQ           = new ResultId(matrixQId); /*!< Orthogonal Matrix Q */
    public static final ResultId matrixR           = new ResultId(matrixRId); /*!< Upper Triangular Matrix R */
    public static final ResultId permutationMatrix = new ResultId(
            permutationMatrixId);                                             /*!< The permutation matrix P overwritten by its details */
}
/** @} */
