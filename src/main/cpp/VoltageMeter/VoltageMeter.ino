/* Copyright [yyyy] [name of copyright owner]
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
 */

#define cellPin A1 // <1>

const float mvc = 2.5; // This is a correction constant

float counts = 0;
float mv = 0;

void setup() {
    Serial.begin(115200); // <2>
}

void loop() {
    counts = analogRead(cellPin);     // <3>
    mv = ((counts * mvc) / 1000) * 2; // <4>
    Serial.println(String(mv));       // <5>
    delay(1000);                      // <6>
}
