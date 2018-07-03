/* file: Batch.java */
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
 * @defgroup bacon_outlier_detection_defaultdense BACON method
 * @brief Contains classes for computing results of the multivariate outlier detection algorithm with BACON method
 * @ingroup bacon_outlier_detection
 * @{
 */
/**
 * @defgroup bacon_outlier_detection_defaultdense_batch Batch
 * @ingroup bacon_outlier_detection_defaultdense
 * @{
 */
/**
 * @brief Contains classes for computing results of the multivariate outlier detection algorithm with BACON method
 */
package com.intel.daal.algorithms.bacon_outlier_detection;

import com.intel.daal.algorithms.AnalysisBatch;
import com.intel.daal.algorithms.ComputeMode;
import com.intel.daal.algorithms.Precision;
import com.intel.daal.services.DaalContext;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__BACON_OUTLIER_DETECTION__BATCH"></a>
 * \brief Runs the multivariate outlier detection algorithm in the batch processing mode.
 * <!-- \n<a href="DAAL-REF-BACON_OUTLIER_DETECTION-ALGORITHM">multivariate outlier detection algorithm description and usage models</a> -->
 *
 * \par References
 *      - InputId class. Identifiers of the input objects for the multivariate outlier detection algorithm
 *      - ResultId class. Identifiers of the results of the algorithm
 */
public class Batch extends AnalysisBatch {
    public Input      input;     /*!< %Input data */
    public Parameter  parameter; /*!< Parameters of the algorithm */
    public Method     method;    /*!< Computation method for the algorithm */
    private Result    result;    /*!< %Result of the algorithm */
    private Precision prec;      /*!< Precision of intermediate computations */

    /** @private */
    static {
        System.loadLibrary("JavaAPI");
    }

    /**
     * Constructs BACON multivariate outlier detection algorithm by copying input objects and parameters
     * of another algorithm BACON multivariate outlier detection algorithm
     * @param context   Context to manage the multivariate outlier detection
     * @param other     An algorithm to be used as the source to initialize the input objects
     *                  and parameters of the algorithm
     */
    public Batch(DaalContext context, Batch other) {
        super(context);
        this.method = other.method;
        prec = other.prec;

        this.cObject = cClone(other.cObject, prec.getValue(), method.getValue());
        input = new Input(getContext(), cGetInput(cObject, prec.getValue(), method.getValue()));
        parameter = new Parameter(getContext(), cInitParameter(this.cObject, prec.getValue(), method.getValue()));
    }

    /**
     * Constructs BACON multivariate outlier detection algorithm
     * @param context   Context to manage the multivariate outlier detection
     * @param cls       Data type to use in intermediate computations of the multivariate outlier detection,
     *                  Double.class or Float.class
     * @param method    multivariate outlier detection computation method, @ref Method
     */
    public Batch(DaalContext context, Class<? extends Number> cls, Method method) {
        super(context);

        this.method = method;

        if (method != Method.defaultDense) {
            throw new IllegalArgumentException("method unsupported");
        }
        if (cls != Double.class && cls != Float.class) {
            throw new IllegalArgumentException("type unsupported");
        }

        if (cls == Double.class) {
            prec = Precision.doublePrecision;
        } else {
            prec = Precision.singlePrecision;
        }

        this.cObject = cInit(prec.getValue(), method.getValue());
        input = new Input(getContext(), cGetInput(cObject, prec.getValue(), method.getValue()));
        parameter = new Parameter(getContext(), cInitParameter(this.cObject, prec.getValue(), method.getValue()));
    }

    /**
     * Runs multivariate outlier detection algorithm
     * @return  Outlier detection results
     */
    @Override
    public Result compute() {
        super.compute();
        result = new Result(getContext(), cGetResult(cObject, prec.getValue(), method.getValue()));
        return result;
    }

    /**
     * Registers user-allocated memory to store the results of the multivariate outlier detection
     * @param result    Structure for storing the results of the multivariate outlier detection algorithm
     */
    public void setResult(Result result) {
        cSetResult(cObject, prec.getValue(), method.getValue(), result.getCObject());
    }

    /**
     * Returns the newly allocated BACON multivariate outlier detection algorithm
     * with a copy of input objects and parameters of this BACON multivariate outlier detection algorithm
     * @param context   Context to manage the multivariate outlier detection
     *
     * @return The newly allocated algorithm
     */
    @Override
    public Batch clone(DaalContext context) {
        return new Batch(context, this);
    }

    private native long cInit(int prec, int method);

    private native long cInitParameter(long algAddr, int prec, int method);

    private native long cGetInput(long algAddr, int prec, int method);

    private native long cGetResult(long algAddr, int prec, int method);

    private native void cSetResult(long cAlgorithm, int prec, int method, long cResult);

    private native long cClone(long algAddr, int prec, int method);
}
/** @} */
/** @} */
