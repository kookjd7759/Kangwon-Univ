# Kangwon national university

3nd year 2nd semester

## Artificial Intelligence
#### Last Project
Grade : 10.00 / 10.00

Grade on : 2022-12-22 22:50

Graded by	: KO SAEJUN

### MLP 구현을 통한 MNIST 숫자 필기체 인식


- MNIST Dataset
  * 0부터 9까지의 숫자 이미지로 구성
  * 하나의 이미지는 28 x 28(pixel) 크기로, 각 pixel은 0에서 255 사이의 값을 취함
  * Txt 파일에 각각의 이미지 정보(784개의 pixel 정보와 정답)가 저장

- MLP(Multi Layer Perceptron)
  * 28 * 28 개 Pixel 정보 x0, x1, ... ,x27을 활용해 가중치 학습을 통한 갱신 및 출력

- Goal
  * Training data에서 epoch 진행에 따른 loss rate 출력
  * Test data의 loss rate 출력
  * ※ loss rate : 예측 실패 데이터 개수 / 전체 데이터 개수 * 100
  * ※ 70000개의 데이터 중 49000개는 training data, 21000개는 test data로 사용

- Reference
  * 제한사항 없음 : Hidden layer node, Learning rate
  * 파일 호출 -> 초기화 -> 활성화 -> 가중치 학습
  * 초기화 과정 : hidden layer node와 output layer node의 threshold와 weight 수준을 균등 분포를 따르는 임의의 실수로 지정
  * 활성화 과정 : input, threshold, weight 값으로 sigmoid 활성화 함수 계산 threshold + Σ input * weight ※ Weight 개수만큼 반복
  * 가중치 학습 : Output layer와 hidden layer의 weight 갱신
    * Output 오차 기울기 : 예측 value * (1 – 예측 value) * (실제 value – 예측 value)
    * Hidden 오차 기울기 : Output layer의 오차 기울기와 Hidden layer에서 Output layer로 가는 weight의 value의 곱셈 합에 value * (1 – value)를 곱함


- Warning
  * Model Structure 필히 작성 (input layer node, hidden layer node, output layer node 개수, Learning rate, epoch)

