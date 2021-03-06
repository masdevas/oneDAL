/* file: XavierBatch.java */
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

/**
 * @defgroup initializers_xavier_batch Batch
 * @ingroup initializers_xavier
 * @{
 */
/**
 * @brief Contains classes for the Xavier initializer
 */
package com.intel.daal.algorithms.neural_networks.initializers.xavier;

import com.intel.daal.utils.*;
import com.intel.daal.algorithms.neural_networks.initializers.Input;
import com.intel.daal.algorithms.neural_networks.initializers.Result;
import com.intel.daal.algorithms.Precision;
import com.intel.daal.services.DaalContext;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__INITIALIZERS__XAVIER__XAVIERBATCH"></a>
 * \brief Provides methods for Xavier initializer computations in the batch processing mode
 *
 * \par References
 *      - @ref com.intel.daal.algorithms.neural_networks.initializers.Input class
 */
public class XavierBatch extends com.intel.daal.algorithms.neural_networks.initializers.InitializerIface {
    public  XavierParameter    parameter; /*!< XavierParameters of the Xavier initializer */
    public  XavierMethod       method;    /*!< Computation method for the initializer */
    private Precision    prec;      /*!< Data type to use in intermediate computations for the initializer */

    /** @private */
    static {
        LibUtils.loadLibrary();
    }

    /**
     * Constructs Xavier initializer by copying input objects and parameters of another Xavier initializer
     * @param context Context to manage the Xavier initializer
     * @param other   An initializer to be used as the source to initialize the input objects
     *                and parameters of this initializer
     */
    public XavierBatch(DaalContext context, XavierBatch other) {
        super(context);
        this.method = other.method;
        prec = other.prec;

        this.cObject = cClone(other.cObject, prec.getValue(), method.getValue());
        input = new Input(context, cGetInput(cObject));
        parameter = new XavierParameter(context, cInitParameter(cObject, prec.getValue(), method.getValue()));
    }

    /**
    * Constructs the Xavier initializer
    * @param context    Context to manage the initializer
    * @param cls        Data type to use in intermediate computations for the initializer, Double.class or Float.class
    * @param method     The initializer computation method, @ref XavierMethod
    */
    public XavierBatch(DaalContext context, Class<? extends Number> cls, XavierMethod method) {
        super(context);
        constructBatch(context, cls, method);
    }

    private void constructBatch(DaalContext context, Class<? extends Number> cls, XavierMethod method) {
        this.method = method;

        if (method != XavierMethod.defaultDense) {
            throw new IllegalArgumentException("method unsupported");
        }
        if (cls != Double.class && cls != Float.class) {
            throw new IllegalArgumentException("type unsupported");
        }

        if (cls == Double.class) {
            prec = Precision.doublePrecision;
        }
        else {
            prec = Precision.singlePrecision;
        }

        this.cObject = cInit(prec.getValue(), method.getValue());
        input = new Input(context, cGetInput(cObject));
        parameter = new XavierParameter(context, cInitParameter(cObject, prec.getValue(), method.getValue()));
    }

    /**
     * Computes the result of the Xavier initializer
     * @return  Xavier initializer result
     */
    @Override
    public Result compute() {
        super.compute();
        return new Result(getContext(), cGetResult(cObject, prec.getValue(), method.getValue()));
    }

    /**
     * Returns the newly allocated Xavier initializer
     * with a copy of input objects and parameters of this Xavier initializer
     * @param context    Context to manage the initializer
     * @return The newly allocated Xavier initializer
     */
    @Override
    public XavierBatch clone(DaalContext context) {
        return new XavierBatch(context, this);
    }

    private native long cInit(int prec, int method);
    private native long cInitParameter(long cAlgorithm, int prec, int method);
    private native long cGetResult(long cAlgorithm, int prec, int method);
    private native long cClone(long algAddr, int prec, int method);
}
/** @} */
