  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 8;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_q8_oppgave2_P)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% heli_q8_oppgave2_P.A_aug
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_oppgave2_P.B_aug
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 25;
	
	  ;% heli_q8_oppgave2_P.C_aug
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 35;
	
	  ;% heli_q8_oppgave2_P.F_aug
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 45;
	
	  ;% heli_q8_oppgave2_P.Joystick_gain_x
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 49;
	
	  ;% heli_q8_oppgave2_P.Joystick_gain_y
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 50;
	
	  ;% heli_q8_oppgave2_P.K_aug
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 51;
	
	  ;% heli_q8_oppgave2_P.Vs_0
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 61;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_oppgave2_P.HILWriteAnalog_channels
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 82;
      section.data(82)  = dumData; %prealloc
      
	  ;% heli_q8_oppgave2_P.HILInitialize_OOTerminate
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_OOExit
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_OOStart
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_OOEnter
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_AOFinal
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_POFinal
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_AIHigh
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_AILow
	  section.data(8).logicalSrcIdx = 16;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_AOHigh
	  section.data(9).logicalSrcIdx = 17;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_AOLow
	  section.data(10).logicalSrcIdx = 18;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_AOInitial
	  section.data(11).logicalSrcIdx = 19;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_AOWatchdog
	  section.data(12).logicalSrcIdx = 20;
	  section.data(12).dtTransOffset = 11;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_POFrequency
	  section.data(13).logicalSrcIdx = 21;
	  section.data(13).dtTransOffset = 12;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_POLeading
	  section.data(14).logicalSrcIdx = 22;
	  section.data(14).dtTransOffset = 13;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_POTrailing
	  section.data(15).logicalSrcIdx = 23;
	  section.data(15).dtTransOffset = 14;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_POInitial
	  section.data(16).logicalSrcIdx = 24;
	  section.data(16).dtTransOffset = 15;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_POWatchdog
	  section.data(17).logicalSrcIdx = 25;
	  section.data(17).dtTransOffset = 16;
	
	  ;% heli_q8_oppgave2_P.TravelCounttorad_Gain
	  section.data(18).logicalSrcIdx = 26;
	  section.data(18).dtTransOffset = 17;
	
	  ;% heli_q8_oppgave2_P.TravelTransferFcn_A
	  section.data(19).logicalSrcIdx = 27;
	  section.data(19).dtTransOffset = 18;
	
	  ;% heli_q8_oppgave2_P.TravelTransferFcn_C
	  section.data(20).logicalSrcIdx = 28;
	  section.data(20).dtTransOffset = 19;
	
	  ;% heli_q8_oppgave2_P.TravelTransferFcn_D
	  section.data(21).logicalSrcIdx = 29;
	  section.data(21).dtTransOffset = 20;
	
	  ;% heli_q8_oppgave2_P.PitchCounttorad_Gain
	  section.data(22).logicalSrcIdx = 30;
	  section.data(22).dtTransOffset = 21;
	
	  ;% heli_q8_oppgave2_P.PitchTransferFcn_A
	  section.data(23).logicalSrcIdx = 31;
	  section.data(23).dtTransOffset = 22;
	
	  ;% heli_q8_oppgave2_P.PitchTransferFcn_C
	  section.data(24).logicalSrcIdx = 32;
	  section.data(24).dtTransOffset = 23;
	
	  ;% heli_q8_oppgave2_P.PitchTransferFcn_D
	  section.data(25).logicalSrcIdx = 33;
	  section.data(25).dtTransOffset = 24;
	
	  ;% heli_q8_oppgave2_P.ElevationCounttorad_Gain
	  section.data(26).logicalSrcIdx = 34;
	  section.data(26).dtTransOffset = 25;
	
	  ;% heli_q8_oppgave2_P.TransferFcn_A
	  section.data(27).logicalSrcIdx = 35;
	  section.data(27).dtTransOffset = 26;
	
	  ;% heli_q8_oppgave2_P.TransferFcn_C
	  section.data(28).logicalSrcIdx = 36;
	  section.data(28).dtTransOffset = 27;
	
	  ;% heli_q8_oppgave2_P.ElevationTransferFcn_A
	  section.data(29).logicalSrcIdx = 37;
	  section.data(29).dtTransOffset = 28;
	
	  ;% heli_q8_oppgave2_P.ElevationTransferFcn_C
	  section.data(30).logicalSrcIdx = 38;
	  section.data(30).dtTransOffset = 29;
	
	  ;% heli_q8_oppgave2_P.ElevationTransferFcn_D
	  section.data(31).logicalSrcIdx = 39;
	  section.data(31).dtTransOffset = 30;
	
	  ;% heli_q8_oppgave2_P.Integrator_IC
	  section.data(32).logicalSrcIdx = 40;
	  section.data(32).dtTransOffset = 31;
	
	  ;% heli_q8_oppgave2_P.Step2_Time
	  section.data(33).logicalSrcIdx = 41;
	  section.data(33).dtTransOffset = 32;
	
	  ;% heli_q8_oppgave2_P.Step2_Y0
	  section.data(34).logicalSrcIdx = 42;
	  section.data(34).dtTransOffset = 33;
	
	  ;% heli_q8_oppgave2_P.Step2_YFinal
	  section.data(35).logicalSrcIdx = 43;
	  section.data(35).dtTransOffset = 34;
	
	  ;% heli_q8_oppgave2_P.Step3_Time
	  section.data(36).logicalSrcIdx = 44;
	  section.data(36).dtTransOffset = 35;
	
	  ;% heli_q8_oppgave2_P.Step3_Y0
	  section.data(37).logicalSrcIdx = 45;
	  section.data(37).dtTransOffset = 36;
	
	  ;% heli_q8_oppgave2_P.Step3_YFinal
	  section.data(38).logicalSrcIdx = 46;
	  section.data(38).dtTransOffset = 37;
	
	  ;% heli_q8_oppgave2_P.Step4_Time
	  section.data(39).logicalSrcIdx = 47;
	  section.data(39).dtTransOffset = 38;
	
	  ;% heli_q8_oppgave2_P.Step4_Y0
	  section.data(40).logicalSrcIdx = 48;
	  section.data(40).dtTransOffset = 39;
	
	  ;% heli_q8_oppgave2_P.Step4_YFinal
	  section.data(41).logicalSrcIdx = 49;
	  section.data(41).dtTransOffset = 40;
	
	  ;% heli_q8_oppgave2_P.Step5_Time
	  section.data(42).logicalSrcIdx = 50;
	  section.data(42).dtTransOffset = 41;
	
	  ;% heli_q8_oppgave2_P.Step5_Y0
	  section.data(43).logicalSrcIdx = 51;
	  section.data(43).dtTransOffset = 42;
	
	  ;% heli_q8_oppgave2_P.Step5_YFinal
	  section.data(44).logicalSrcIdx = 52;
	  section.data(44).dtTransOffset = 43;
	
	  ;% heli_q8_oppgave2_P.Constant1_Value
	  section.data(45).logicalSrcIdx = 53;
	  section.data(45).dtTransOffset = 44;
	
	  ;% heli_q8_oppgave2_P.RateTransitionx_InitialConditio
	  section.data(46).logicalSrcIdx = 54;
	  section.data(46).dtTransOffset = 45;
	
	  ;% heli_q8_oppgave2_P.DeadZonex_Start
	  section.data(47).logicalSrcIdx = 55;
	  section.data(47).dtTransOffset = 46;
	
	  ;% heli_q8_oppgave2_P.DeadZonex_End
	  section.data(48).logicalSrcIdx = 56;
	  section.data(48).dtTransOffset = 47;
	
	  ;% heli_q8_oppgave2_P.Gainx_Gain
	  section.data(49).logicalSrcIdx = 57;
	  section.data(49).dtTransOffset = 48;
	
	  ;% heli_q8_oppgave2_P.Switch_Threshold
	  section.data(50).logicalSrcIdx = 58;
	  section.data(50).dtTransOffset = 49;
	
	  ;% heli_q8_oppgave2_P.Step_Time
	  section.data(51).logicalSrcIdx = 59;
	  section.data(51).dtTransOffset = 50;
	
	  ;% heli_q8_oppgave2_P.Step_Y0
	  section.data(52).logicalSrcIdx = 60;
	  section.data(52).dtTransOffset = 51;
	
	  ;% heli_q8_oppgave2_P.Step_YFinal
	  section.data(53).logicalSrcIdx = 61;
	  section.data(53).dtTransOffset = 52;
	
	  ;% heli_q8_oppgave2_P.Step1_Time
	  section.data(54).logicalSrcIdx = 62;
	  section.data(54).dtTransOffset = 53;
	
	  ;% heli_q8_oppgave2_P.Step1_Y0
	  section.data(55).logicalSrcIdx = 63;
	  section.data(55).dtTransOffset = 54;
	
	  ;% heli_q8_oppgave2_P.Step1_YFinal
	  section.data(56).logicalSrcIdx = 64;
	  section.data(56).dtTransOffset = 55;
	
	  ;% heli_q8_oppgave2_P.Step6_Time
	  section.data(57).logicalSrcIdx = 65;
	  section.data(57).dtTransOffset = 56;
	
	  ;% heli_q8_oppgave2_P.Step6_Y0
	  section.data(58).logicalSrcIdx = 66;
	  section.data(58).dtTransOffset = 57;
	
	  ;% heli_q8_oppgave2_P.Step6_YFinal
	  section.data(59).logicalSrcIdx = 67;
	  section.data(59).dtTransOffset = 58;
	
	  ;% heli_q8_oppgave2_P.Step7_Time
	  section.data(60).logicalSrcIdx = 68;
	  section.data(60).dtTransOffset = 59;
	
	  ;% heli_q8_oppgave2_P.Step7_Y0
	  section.data(61).logicalSrcIdx = 69;
	  section.data(61).dtTransOffset = 60;
	
	  ;% heli_q8_oppgave2_P.Step7_YFinal
	  section.data(62).logicalSrcIdx = 70;
	  section.data(62).dtTransOffset = 61;
	
	  ;% heli_q8_oppgave2_P.Step8_Time
	  section.data(63).logicalSrcIdx = 71;
	  section.data(63).dtTransOffset = 62;
	
	  ;% heli_q8_oppgave2_P.Step8_Y0
	  section.data(64).logicalSrcIdx = 72;
	  section.data(64).dtTransOffset = 63;
	
	  ;% heli_q8_oppgave2_P.Step8_YFinal
	  section.data(65).logicalSrcIdx = 73;
	  section.data(65).dtTransOffset = 64;
	
	  ;% heli_q8_oppgave2_P.RateTransitiony_InitialConditio
	  section.data(66).logicalSrcIdx = 74;
	  section.data(66).dtTransOffset = 65;
	
	  ;% heli_q8_oppgave2_P.DeadZoney_Start
	  section.data(67).logicalSrcIdx = 75;
	  section.data(67).dtTransOffset = 66;
	
	  ;% heli_q8_oppgave2_P.DeadZoney_End
	  section.data(68).logicalSrcIdx = 76;
	  section.data(68).dtTransOffset = 67;
	
	  ;% heli_q8_oppgave2_P.Gainy_Gain
	  section.data(69).logicalSrcIdx = 77;
	  section.data(69).dtTransOffset = 68;
	
	  ;% heli_q8_oppgave2_P.Gain2_Gain
	  section.data(70).logicalSrcIdx = 78;
	  section.data(70).dtTransOffset = 69;
	
	  ;% heli_q8_oppgave2_P.Switch1_Threshold
	  section.data(71).logicalSrcIdx = 79;
	  section.data(71).dtTransOffset = 70;
	
	  ;% heli_q8_oppgave2_P.Frontgain_Gain
	  section.data(72).logicalSrcIdx = 80;
	  section.data(72).dtTransOffset = 71;
	
	  ;% heli_q8_oppgave2_P.Backgain_Gain
	  section.data(73).logicalSrcIdx = 81;
	  section.data(73).dtTransOffset = 72;
	
	  ;% heli_q8_oppgave2_P.StateSpace_C
	  section.data(74).logicalSrcIdx = 82;
	  section.data(74).dtTransOffset = 73;
	
	  ;% heli_q8_oppgave2_P.StateSpace_InitialCondition
	  section.data(75).logicalSrcIdx = 83;
	  section.data(75).dtTransOffset = 98;
	
	  ;% heli_q8_oppgave2_P.TransferFcn_A_a
	  section.data(76).logicalSrcIdx = 84;
	  section.data(76).dtTransOffset = 99;
	
	  ;% heli_q8_oppgave2_P.TransferFcn_C_k
	  section.data(77).logicalSrcIdx = 85;
	  section.data(77).dtTransOffset = 100;
	
	  ;% heli_q8_oppgave2_P.FrontmotorSaturation_UpperSat
	  section.data(78).logicalSrcIdx = 86;
	  section.data(78).dtTransOffset = 101;
	
	  ;% heli_q8_oppgave2_P.FrontmotorSaturation_LowerSat
	  section.data(79).logicalSrcIdx = 87;
	  section.data(79).dtTransOffset = 102;
	
	  ;% heli_q8_oppgave2_P.BackmotorSaturation_UpperSat
	  section.data(80).logicalSrcIdx = 88;
	  section.data(80).dtTransOffset = 103;
	
	  ;% heli_q8_oppgave2_P.BackmotorSaturation_LowerSat
	  section.data(81).logicalSrcIdx = 89;
	  section.data(81).dtTransOffset = 104;
	
	  ;% heli_q8_oppgave2_P.Integrator_IC_d
	  section.data(82).logicalSrcIdx = 90;
	  section.data(82).dtTransOffset = 105;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% heli_q8_oppgave2_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 91;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_DOWatchdog
	  section.data(2).logicalSrcIdx = 92;
	  section.data(2).dtTransOffset = 3;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_EIInitial
	  section.data(3).logicalSrcIdx = 93;
	  section.data(3).dtTransOffset = 4;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_POModes
	  section.data(4).logicalSrcIdx = 94;
	  section.data(4).dtTransOffset = 5;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_POConfiguration
	  section.data(5).logicalSrcIdx = 95;
	  section.data(5).dtTransOffset = 6;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_POAlignment
	  section.data(6).logicalSrcIdx = 96;
	  section.data(6).dtTransOffset = 7;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_POPolarity
	  section.data(7).logicalSrcIdx = 97;
	  section.data(7).dtTransOffset = 8;
	
	  ;% heli_q8_oppgave2_P.HILReadEncoderTimebase_Clock
	  section.data(8).logicalSrcIdx = 98;
	  section.data(8).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% heli_q8_oppgave2_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 99;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_AOChannels
	  section.data(2).logicalSrcIdx = 100;
	  section.data(2).dtTransOffset = 8;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_EIChannels
	  section.data(3).logicalSrcIdx = 101;
	  section.data(3).dtTransOffset = 16;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_EIQuadrature
	  section.data(4).logicalSrcIdx = 102;
	  section.data(4).dtTransOffset = 24;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_POChannels
	  section.data(5).logicalSrcIdx = 103;
	  section.data(5).dtTransOffset = 25;
	
	  ;% heli_q8_oppgave2_P.HILReadEncoderTimebase_Channels
	  section.data(6).logicalSrcIdx = 104;
	  section.data(6).dtTransOffset = 33;
	
	  ;% heli_q8_oppgave2_P.HILReadEncoderTimebase_SamplesI
	  section.data(7).logicalSrcIdx = 105;
	  section.data(7).dtTransOffset = 36;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_oppgave2_P.GameController_BufferSize
	  section.data(1).logicalSrcIdx = 106;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 39;
      section.data(39)  = dumData; %prealloc
      
	  ;% heli_q8_oppgave2_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 107;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_AOTerminate
	  section.data(2).logicalSrcIdx = 108;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_AOExit
	  section.data(3).logicalSrcIdx = 109;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_DOTerminate
	  section.data(4).logicalSrcIdx = 110;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_DOExit
	  section.data(5).logicalSrcIdx = 111;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_POTerminate
	  section.data(6).logicalSrcIdx = 112;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_POExit
	  section.data(7).logicalSrcIdx = 113;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_CKPStart
	  section.data(8).logicalSrcIdx = 114;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_CKPEnter
	  section.data(9).logicalSrcIdx = 115;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_CKStart
	  section.data(10).logicalSrcIdx = 116;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_CKEnter
	  section.data(11).logicalSrcIdx = 117;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_AIPStart
	  section.data(12).logicalSrcIdx = 118;
	  section.data(12).dtTransOffset = 11;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_AIPEnter
	  section.data(13).logicalSrcIdx = 119;
	  section.data(13).dtTransOffset = 12;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_AOPStart
	  section.data(14).logicalSrcIdx = 120;
	  section.data(14).dtTransOffset = 13;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_AOPEnter
	  section.data(15).logicalSrcIdx = 121;
	  section.data(15).dtTransOffset = 14;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_AOStart
	  section.data(16).logicalSrcIdx = 122;
	  section.data(16).dtTransOffset = 15;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_AOEnter
	  section.data(17).logicalSrcIdx = 123;
	  section.data(17).dtTransOffset = 16;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_AOReset
	  section.data(18).logicalSrcIdx = 124;
	  section.data(18).dtTransOffset = 17;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_DOPStart
	  section.data(19).logicalSrcIdx = 125;
	  section.data(19).dtTransOffset = 18;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_DOPEnter
	  section.data(20).logicalSrcIdx = 126;
	  section.data(20).dtTransOffset = 19;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_DOStart
	  section.data(21).logicalSrcIdx = 127;
	  section.data(21).dtTransOffset = 20;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_DOEnter
	  section.data(22).logicalSrcIdx = 128;
	  section.data(22).dtTransOffset = 21;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_DOReset
	  section.data(23).logicalSrcIdx = 129;
	  section.data(23).dtTransOffset = 22;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_EIPStart
	  section.data(24).logicalSrcIdx = 130;
	  section.data(24).dtTransOffset = 23;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_EIPEnter
	  section.data(25).logicalSrcIdx = 131;
	  section.data(25).dtTransOffset = 24;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_EIStart
	  section.data(26).logicalSrcIdx = 132;
	  section.data(26).dtTransOffset = 25;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_EIEnter
	  section.data(27).logicalSrcIdx = 133;
	  section.data(27).dtTransOffset = 26;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_POPStart
	  section.data(28).logicalSrcIdx = 134;
	  section.data(28).dtTransOffset = 27;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_POPEnter
	  section.data(29).logicalSrcIdx = 135;
	  section.data(29).dtTransOffset = 28;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_POStart
	  section.data(30).logicalSrcIdx = 136;
	  section.data(30).dtTransOffset = 29;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_POEnter
	  section.data(31).logicalSrcIdx = 137;
	  section.data(31).dtTransOffset = 30;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 138;
	  section.data(32).dtTransOffset = 31;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 139;
	  section.data(33).dtTransOffset = 32;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_DOFinal
	  section.data(34).logicalSrcIdx = 140;
	  section.data(34).dtTransOffset = 33;
	
	  ;% heli_q8_oppgave2_P.HILInitialize_DOInitial
	  section.data(35).logicalSrcIdx = 141;
	  section.data(35).dtTransOffset = 34;
	
	  ;% heli_q8_oppgave2_P.HILReadEncoderTimebase_Active
	  section.data(36).logicalSrcIdx = 142;
	  section.data(36).dtTransOffset = 35;
	
	  ;% heli_q8_oppgave2_P.HILWriteAnalog_Active
	  section.data(37).logicalSrcIdx = 143;
	  section.data(37).dtTransOffset = 36;
	
	  ;% heli_q8_oppgave2_P.GameController_AutoCenter
	  section.data(38).logicalSrcIdx = 144;
	  section.data(38).dtTransOffset = 37;
	
	  ;% heli_q8_oppgave2_P.GameController_Enabled
	  section.data(39).logicalSrcIdx = 145;
	  section.data(39).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% heli_q8_oppgave2_P.HILReadEncoderTimebase_Overflow
	  section.data(1).logicalSrcIdx = 146;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_oppgave2_P.GameController_ControllerNumber
	  section.data(2).logicalSrcIdx = 147;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_q8_oppgave2_B)
    ;%
      section.nData     = 26;
      section.data(26)  = dumData; %prealloc
      
	  ;% heli_q8_oppgave2_B.TravelCounttorad
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_oppgave2_B.TravelTransferFcn
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_oppgave2_B.PitchCounttorad
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_oppgave2_B.PitchTransferFcn
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_oppgave2_B.ElevationCounttorad
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_oppgave2_B.TransferFcn
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_oppgave2_B.ElevationTransferFcn
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_oppgave2_B.Integrator
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_q8_oppgave2_B.RateTransitionx
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 9;
	
	  ;% heli_q8_oppgave2_B.Joystick_gain_x
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 10;
	
	  ;% heli_q8_oppgave2_B.Switch
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 11;
	
	  ;% heli_q8_oppgave2_B.RateTransitiony
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 12;
	
	  ;% heli_q8_oppgave2_B.Joystick_gain_y
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 13;
	
	  ;% heli_q8_oppgave2_B.Gain2
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 14;
	
	  ;% heli_q8_oppgave2_B.Switch1
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 15;
	
	  ;% heli_q8_oppgave2_B.u
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 16;
	
	  ;% heli_q8_oppgave2_B.Sum1
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 18;
	
	  ;% heli_q8_oppgave2_B.Frontgain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 19;
	
	  ;% heli_q8_oppgave2_B.Backgain
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 20;
	
	  ;% heli_q8_oppgave2_B.Gain1
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 21;
	
	  ;% heli_q8_oppgave2_B.elevationrate
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 23;
	
	  ;% heli_q8_oppgave2_B.FrontmotorSaturation
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 24;
	
	  ;% heli_q8_oppgave2_B.BackmotorSaturation
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 25;
	
	  ;% heli_q8_oppgave2_B.u_d
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 26;
	
	  ;% heli_q8_oppgave2_B.TmpSignalConversionAtIntegrator
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 28;
	
	  ;% heli_q8_oppgave2_B.TmpSignalConversionAtIntegrat_p
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 30;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 8;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_q8_oppgave2_DW)
    ;%
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% heli_q8_oppgave2_DW.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_oppgave2_DW.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 8;
	
	  ;% heli_q8_oppgave2_DW.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 16;
	
	  ;% heli_q8_oppgave2_DW.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 24;
	
	  ;% heli_q8_oppgave2_DW.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 32;
	
	  ;% heli_q8_oppgave2_DW.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 40;
	
	  ;% heli_q8_oppgave2_DW.HILInitialize_POSortedFreqs
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 48;
	
	  ;% heli_q8_oppgave2_DW.HILInitialize_POValues
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 56;
	
	  ;% heli_q8_oppgave2_DW.RateTransitionx_Buffer0
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 64;
	
	  ;% heli_q8_oppgave2_DW.RateTransitiony_Buffer0
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 65;
	
	  ;% heli_q8_oppgave2_DW.HILWriteAnalog_Buffer
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 66;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_oppgave2_DW.GameController_Controller
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_oppgave2_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_oppgave2_DW.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% heli_q8_oppgave2_DW.ToFile_PWORK.FilePtr
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_oppgave2_DW.Scope1_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_oppgave2_DW.Scope3_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_oppgave2_DW.ElevationScoperads_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 4;
	
	  ;% heli_q8_oppgave2_DW.ElevationScoperad_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 18;
	  section.data(5).dtTransOffset = 5;
	
	  ;% heli_q8_oppgave2_DW.PitchScoperad_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 19;
	  section.data(6).dtTransOffset = 6;
	
	  ;% heli_q8_oppgave2_DW.PtichrateScoperads_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 20;
	  section.data(7).dtTransOffset = 7;
	
	  ;% heli_q8_oppgave2_DW.TravelrateScoperads_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 21;
	  section.data(8).dtTransOffset = 8;
	
	  ;% heli_q8_oppgave2_DW.TravelScoperad_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 22;
	  section.data(9).dtTransOffset = 9;
	
	  ;% heli_q8_oppgave2_DW.HILWriteAnalog_PWORK
	  section.data(10).logicalSrcIdx = 23;
	  section.data(10).dtTransOffset = 10;
	
	  ;% heli_q8_oppgave2_DW.XScope_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 24;
	  section.data(11).dtTransOffset = 11;
	
	  ;% heli_q8_oppgave2_DW.YScope_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 25;
	  section.data(12).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% heli_q8_oppgave2_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_oppgave2_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 27;
	  section.data(2).dtTransOffset = 3;
	
	  ;% heli_q8_oppgave2_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 28;
	  section.data(3).dtTransOffset = 11;
	
	  ;% heli_q8_oppgave2_DW.HILInitialize_POModeValues
	  section.data(4).logicalSrcIdx = 29;
	  section.data(4).dtTransOffset = 19;
	
	  ;% heli_q8_oppgave2_DW.HILInitialize_POAlignValues
	  section.data(5).logicalSrcIdx = 30;
	  section.data(5).dtTransOffset = 27;
	
	  ;% heli_q8_oppgave2_DW.HILInitialize_POPolarityVals
	  section.data(6).logicalSrcIdx = 31;
	  section.data(6).dtTransOffset = 35;
	
	  ;% heli_q8_oppgave2_DW.HILReadEncoderTimebase_Buffer
	  section.data(7).logicalSrcIdx = 32;
	  section.data(7).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_oppgave2_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_oppgave2_DW.ToFile_IWORK.Count
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2992817522;
  targMap.checksum1 = 2743806836;
  targMap.checksum2 = 3780859591;
  targMap.checksum3 = 1490995438;

