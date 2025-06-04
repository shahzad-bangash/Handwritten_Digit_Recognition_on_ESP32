#include "headers/model_data.h"
#include "headers/mnist_image_array.h"
#include <tflm_esp32.h>
#include <eloquent_tinyml.h>

#define ARENA_SIZE 10000
Eloquent::TF::Sequential<TF_NUM_OPS, ARENA_SIZE> tf;

void setup() {
    Serial.begin(115200);
    delay(3000);
    Serial.println("__TENSORFLOW MNISTModel");
 
    while (!tf.begin(MNISTModel).isOk())
        Serial.println(tf.exception.toString());
}


void loop() {
 
    // classify sample from 
    if (!tf.predict(image).isOk()) {
        Serial.println(tf.exception.toString());
        return;  
    }
    Serial.print("Predicted class ");
    Serial.print(tf.classification);
    Serial.println("");
    Serial.print("It takes ");
    Serial.print(tf.benchmark.microseconds());
    Serial.println("us for a single prediction");
    Serial.println("");
    delay(1000);
}
