/* file: neural_networks_training_topology.h */
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

#ifndef __NEURAL_NETWORKS_TRAINING_TOPOLOGY_H__
#define __NEURAL_NETWORKS_TRAINING_TOPOLOGY_H__

#include "algorithms/neural_networks/layers/layer_descriptor.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace training
{
namespace interface1
{
/**
 * @ingroup neural_networks_training
 * @{
 */
/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__TRAINING__TOPOLOGY"></a>
 * \brief Class defining a neural network topology - a set of layers and connection between them -
 *        on the training stage
 */
class Topology: public Base
{
public:
    /** Default constructor */
    Topology() {}

    /**
     * Constructs neural network topology by copying layers of another topology
     * \param[in] t  Neural network topology to be used as the source to initialize layers
     */
    Topology(const Topology &t) : _config(t.size())
    {
        for(size_t i = 0; i < t.size(); i++)
        {
            _config[i] = layers::LayerDescriptor(i, t[i].layer(), t[i].nextLayers());
        }
    }

    /**
     * Number of layers in the topology
     * \return Size of the collection
     */
    size_t size() const { return _config.size(); }

    /**
    *  Adds an element to the collection of layers and assigns the next available id to it
    *  \param[in] layer Element to add
    *  \return Index of the element
    */
    size_t push_back(const layers::LayerIfacePtr &layer)
    {
        size_t id = _config.size();
        _config.push_back(layers::LayerDescriptor(id, layer));
        return id;
    }

    /**
    *  Adds an element to the collection of layers and assigns the next available id to it
    *  \param[in] layer Element to add
    *  \return    Index of the element
    */
    size_t add(const layers::LayerIfacePtr &layer)
    {
        return push_back(layer);
    }

    /**
    *  Adds a block of elements to the collection of layers
    *  \param[in] topologyBlock Block to add
    *  \param[in] startIndex    Index of the first element of the block in topology
    *  \return    Index of the last element of the block in topology
    */
    size_t add(const Topology &topologyBlock, size_t &startIndex)
    {
        size_t size = _config.size();
        startIndex = size;

        size_t id = 0;
        for(size_t i = 0; i < topologyBlock.size(); i++)
        {
            id = push_back(topologyBlock[i].layer());

            const layers::NextLayers& nextLayers = topologyBlock[i].nextLayers();
            for(size_t j = 0; j < nextLayers.size(); j++)
            {
                get(i + size).addNext(nextLayers[j] + size);
            }
        }
        return id;
    }

    /**
     *  Clears a topology: removes all layer descriptors and sets size to 0
     *
     * \return Status of computations
     */
    services::Status clear()
    {
        _config.clear();
        return services::Status();
    }

    /**
     * Element access
     * \param[in] index Index of an accessed element
     * \return    Reference to the element
     */
    layers::LayerDescriptor& operator [] (size_t index) { return _config[index]; }

    /**
     * Const element access
     * \param[in] index Index of an accessed element
     * \return    Reference to the element
     */
    const layers::LayerDescriptor& operator [] (size_t index) const { return _config[index]; }

    /**
     * Element access
     * \param[in] index Index of an accessed element
     * \return    Reference to the element
     */
    layers::LayerDescriptor& get(size_t index) { return _config[index]; }

    /**
     * Const element access
     * \param[in] index Index of an accessed element
     * \return    Reference to the element
     */
    const layers::LayerDescriptor& get(size_t index) const { return _config[index]; }

    /**
     * Adds next layer to the given layer
     * \param[in] index Index of the layer to add next layer
     * \param[in] next Index of the next layer
     * \DAAL_DEPRECATED_USE{ Topology::get } Following with LayerDescriptor::addNext method.
     *
     * \return Status of computations
    */
    DAAL_DEPRECATED services::Status addNext(size_t index, size_t next)
    {
        _config[index].addNext(next);
        return services::Status();
    }

protected:
    services::Collection<layers::LayerDescriptor> _config;
};

typedef services::SharedPtr<Topology> TopologyPtr;
/** @} */
}
using interface1::Topology;
using interface1::TopologyPtr;
}
}
}
}

#endif
