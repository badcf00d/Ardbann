/*
  Ardbann.h - ARDuino Backpropogating Artificial Neural Network.
  Created by Peter Frost, February 9, 2017.
  Released into the public domain.
*/
#ifndef Ardbann_h
#define Ardbann_h

#include "Arduino.h"

struct InputLayer
{
    uint16_t numNeurons;
    uint16_t numRawInputs;
    uint16_t maxInput;
    uint16_t *rawInputs;
    float *neurons;
};

struct HiddenLayer
{
    uint16_t numNeurons;
    uint8_t numLayers;
    float **neuronTable;
    float ** *weightLayerTable;
};

struct OutputLayer
{
    String *stringArray;
    uint16_t numNeurons;
    float *neurons;
    float **weightTable;
};

struct Network
{
    uint16_t numLayers;
    uint16_t networkResponse;
    InputLayer inputLayer;
    HiddenLayer hiddenLayer;
    OutputLayer outputLayer;
};

class Ardbann
{
public:
    Ardbann(uint16_t rawInputArray[], uint16_t maxInput, String outputArray[], const uint16_t numInputs,
            const uint16_t numInputNeurons,  const uint16_t numHiddenNeurons,
            const uint8_t numHiddenLayers, const uint16_t numOutputNeurons);
    uint8_t InputLayer();
    void SumAndSquash(float *pointerToInput, float *pointerToOutput, float **pointerToWeights,
                  uint16_t numInputs, uint16_t numOutputs);
    uint8_t OutputLayer();
    void PrintNetwork();
    void Train(uint8_t correctOutput, uint32_t numSeconds, float learningRate);
    float tanhDerivative(float inputValue);
private:
    Network network;
};

#endif