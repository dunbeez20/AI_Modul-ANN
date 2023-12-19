void setup() {
  Serial.begin(9600);
}
void loop() {
  // input random value
  int harta = random(0, 3);
  int hutang = random(0, 3);
  float input1, input2, input3, input4, input5, input6, layer1d1, layer1d2, layer1w1,
    layer1w2, layer1w3, layer1b1, layer1b2, layer1b3, layer1n1, layer1n2, layer1n3,
    layer1t1, layer1t2, layer1t3, layer2d1, layer2d2, layer2d3, layer2w1, layer2w2,
    layer2b1, layer2b2, layer2n1, layer2n2, layer2p1, layer2p2, output1, output2,
    output3, output4, output5, output6;
  //aritmatika masing-masing proses neuron
  input1 = harta - 10;      // dikurang xmin A1
  input2 = hutang - 10;     // dikurang xmin A2
  input3 = input1 * 0.0125;
  input4 = input2 * 0.0166;
  input5 = input3 + 0;      // dikurang ymin
  input6 = input4 + 0;      // dikurang ymin
 
  layer1d1 = input5;
  layer1d2 = input6;
  // Layer 1 weight
  layer1w1 = (layer1d1 * 0.04) + (layer1d2 * -1.39);

  // Layer 1 Bias
  layer1b1 = 0;

  // Layer 1 Netsum
  layer1n1 = layer1w1 + layer1b1;

  // Layer 1 Tansig 1
  layer1t1 = (2 / (( exp (layer1n1 * -2)) + 1) - 1);
  //layer1t2 = (2 / (pow(2.718, layer1n2 * -2) + 1) - 1);
 
  // Layer 1 Tansig 2
  layer1t2 = (((layer1n1 * -2 * exp (layer1n1)) +1) * (2 / layer1n1)-1);
  
  // Layer 1 Delay
  layer2d1 = layer1t1;
  layer2d2 = layer1t2;


  // Layer 2 Weight
  layer2w1 = (layer2d1 * 0.781) + (layer2d2 * 0.781); 

  // Layer 2 Bias
  layer2b1 = -0.722188542603478;

  // Layer 2 Netsum
  layer2n1 = layer2w1 + layer2b1;
  
  // Layer 2 Purelin
  layer2p1 = layer2w1 + layer2b1;

  // Output
  output1 = layer2p1 + 0;       // u-ymin

  output3 = output1 * 80;       // K1
  output4 = output1 * 60;       // K2

  output5 = output3 + 10;       // Y1
  output6 = output4 + 10;       // Y2
  //input value
  Serial.print("harta: ");
  Serial.println(harta);
  Serial.print("hutang: ");
  Serial.println(hutang);
  //hasil
  Serial.print("status : ");
  Serial.println(output5);
  Serial.print("hasil : ");

  Serial.println(output6);
  delay(5000);
}