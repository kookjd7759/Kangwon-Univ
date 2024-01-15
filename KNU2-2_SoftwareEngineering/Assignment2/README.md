# Kangwon national university

2nd year 2nd semester

## Software engineering
#### Second Project
Grade : 35/35

Grade on : 2021-12-13 06:06

Graded by	: Se Jin Kwon

### Flash Memory Mapphing Algorithm


- 플래시 메모리 구성
- 섹터와 블록 매핑 알고리즘 구현

가정해야 할 부분이 존재한다면 가정할 것 (여분 블록, 추가 DRAM 등 가정 가능)



- 구현 함수:
  * init ( ); //플래시 메모리 생성
  * Print_table ( ) ; //매핑 테이블 출력
  * Flash_read ( ); //플래시 메모리 하드웨어 구성 read, write, erase
  * Flash_write ( );
  * Flash_erase ( );
  * FTL_read ( );
  * FTL_write ( );

- Input 명령어: 
  * init megabytes // x megabytes 플래시 메모리 생성
  * R PSN // 해당 PSN 에서 데이터 읽어오기
  * W PSN data // 해당 PSN 섹터에 데이터 적기
  * E PBN // 해당 PBN 블록을 지우기
  * read LSN
  * write LSN data

- 결과값:
  * init 의 ouput: x megabytes flash memory ;
  * read 의 output: 해당되는 PSN 와 데이터 출력
  * write 의 output: done,
    * 실제로 수행된 FLASH_read 횟수
    * 실제로 수행된 FLASH_write 횟수
    * 실제로 수행된 FLASH_erase 횟수 예) 쓰기 완료,, 쓰기 5 회, 지우기 연산 (PBN 13)



