  int tmp2 = 64 << 1; // 64 := ...01000000; tmp2 := ...10000000
  cout << tmp2;


  // start:  0001 0110
  // idea:   1001 0110

  // siCrea: 1000 0000

  // 

  int tmp3 = 1; // 0000 0001
  for (int i = 0; i < PosizionePassata; i++)
    tmp3 = tmp3 << 1;