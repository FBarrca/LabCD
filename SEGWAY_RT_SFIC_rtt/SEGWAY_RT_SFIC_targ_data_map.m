  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
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
    ;% Auto data (SEGWAY_RT_SFIC_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% SEGWAY_RT_SFIC_P.ts
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% SEGWAY_RT_SFIC_P.Kcd
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SEGWAY_RT_SFIC_P.R
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 3;
	
	  ;% SEGWAY_RT_SFIC_P.Wfc
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 4;
	
	  ;% SEGWAY_RT_SFIC_P.alfa1
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 5;
	
	  ;% SEGWAY_RT_SFIC_P.gyro0
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 6;
	
	  ;% SEGWAY_RT_SFIC_P.sound_freq
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 7;
	
	  ;% SEGWAY_RT_SFIC_P.time_start
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 8;
	
	  ;% SEGWAY_RT_SFIC_P.Calculodelavelocidadapartirdelc
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 9;
	
	  ;% SEGWAY_RT_SFIC_P.Calculodelavelocidadapartirde_j
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% SEGWAY_RT_SFIC_P.Speaker_speakerVolume
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% SEGWAY_RT_SFIC_P.Gain6_Gain
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SEGWAY_RT_SFIC_P.Gain1_Gain
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
	  ;% SEGWAY_RT_SFIC_P.Constant_Value
	  section.data(3).logicalSrcIdx = 13;
	  section.data(3).dtTransOffset = 2;
	
	  ;% SEGWAY_RT_SFIC_P.PulseGenerator_Amp
	  section.data(4).logicalSrcIdx = 14;
	  section.data(4).dtTransOffset = 3;
	
	  ;% SEGWAY_RT_SFIC_P.PulseGenerator_PhaseDelay
	  section.data(5).logicalSrcIdx = 15;
	  section.data(5).dtTransOffset = 4;
	
	  ;% SEGWAY_RT_SFIC_P.deg2rad3_Gain
	  section.data(6).logicalSrcIdx = 16;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 50;
      section.data(50)  = dumData; %prealloc
      
	  ;% SEGWAY_RT_SFIC_P.Gain8_Gain
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SEGWAY_RT_SFIC_P.Gain1_Gain_a
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% SEGWAY_RT_SFIC_P.Gain3_Gain
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
	  ;% SEGWAY_RT_SFIC_P.Pasoarads_Gain
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 3;
	
	  ;% SEGWAY_RT_SFIC_P.Gain3_Gain_g
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 4;
	
	  ;% SEGWAY_RT_SFIC_P.UnitDelay_InitialCondition
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 5;
	
	  ;% SEGWAY_RT_SFIC_P.DiscreteTransferFcn_NumCoef
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 6;
	
	  ;% SEGWAY_RT_SFIC_P.DiscreteTransferFcn_DenCoef
	  section.data(8).logicalSrcIdx = 24;
	  section.data(8).dtTransOffset = 8;
	
	  ;% SEGWAY_RT_SFIC_P.DiscreteTransferFcn_InitialStat
	  section.data(9).logicalSrcIdx = 25;
	  section.data(9).dtTransOffset = 10;
	
	  ;% SEGWAY_RT_SFIC_P.Pasoarads_Gain_j
	  section.data(10).logicalSrcIdx = 26;
	  section.data(10).dtTransOffset = 11;
	
	  ;% SEGWAY_RT_SFIC_P.Gain3_Gain_k
	  section.data(11).logicalSrcIdx = 27;
	  section.data(11).dtTransOffset = 12;
	
	  ;% SEGWAY_RT_SFIC_P.UnitDelay_InitialCondition_j
	  section.data(12).logicalSrcIdx = 28;
	  section.data(12).dtTransOffset = 13;
	
	  ;% SEGWAY_RT_SFIC_P.DiscreteTransferFcn_NumCoef_c
	  section.data(13).logicalSrcIdx = 29;
	  section.data(13).dtTransOffset = 14;
	
	  ;% SEGWAY_RT_SFIC_P.DiscreteTransferFcn_DenCoef_c
	  section.data(14).logicalSrcIdx = 30;
	  section.data(14).dtTransOffset = 16;
	
	  ;% SEGWAY_RT_SFIC_P.DiscreteTransferFcn_InitialSt_b
	  section.data(15).logicalSrcIdx = 31;
	  section.data(15).dtTransOffset = 18;
	
	  ;% SEGWAY_RT_SFIC_P.Gain_Gain
	  section.data(16).logicalSrcIdx = 32;
	  section.data(16).dtTransOffset = 19;
	
	  ;% SEGWAY_RT_SFIC_P.deg2rad4_Gain
	  section.data(17).logicalSrcIdx = 33;
	  section.data(17).dtTransOffset = 20;
	
	  ;% SEGWAY_RT_SFIC_P.Gain3_Gain_a
	  section.data(18).logicalSrcIdx = 34;
	  section.data(18).dtTransOffset = 21;
	
	  ;% SEGWAY_RT_SFIC_P.UnitDelay_InitialCondition_o
	  section.data(19).logicalSrcIdx = 35;
	  section.data(19).dtTransOffset = 22;
	
	  ;% SEGWAY_RT_SFIC_P.Gain3_Gain_f
	  section.data(20).logicalSrcIdx = 36;
	  section.data(20).dtTransOffset = 23;
	
	  ;% SEGWAY_RT_SFIC_P.deg2rad5_Gain
	  section.data(21).logicalSrcIdx = 37;
	  section.data(21).dtTransOffset = 24;
	
	  ;% SEGWAY_RT_SFIC_P.deg2rad2_Gain
	  section.data(22).logicalSrcIdx = 38;
	  section.data(22).dtTransOffset = 25;
	
	  ;% SEGWAY_RT_SFIC_P.Gain2_Gain
	  section.data(23).logicalSrcIdx = 39;
	  section.data(23).dtTransOffset = 26;
	
	  ;% SEGWAY_RT_SFIC_P.UnitDelay1_InitialCondition
	  section.data(24).logicalSrcIdx = 40;
	  section.data(24).dtTransOffset = 27;
	
	  ;% SEGWAY_RT_SFIC_P.Gain1_Gain_i
	  section.data(25).logicalSrcIdx = 41;
	  section.data(25).dtTransOffset = 28;
	
	  ;% SEGWAY_RT_SFIC_P.UnitDelay_InitialCondition_m
	  section.data(26).logicalSrcIdx = 42;
	  section.data(26).dtTransOffset = 29;
	
	  ;% SEGWAY_RT_SFIC_P.Gain4_Gain
	  section.data(27).logicalSrcIdx = 43;
	  section.data(27).dtTransOffset = 30;
	
	  ;% SEGWAY_RT_SFIC_P.deg2rad1_Gain
	  section.data(28).logicalSrcIdx = 44;
	  section.data(28).dtTransOffset = 31;
	
	  ;% SEGWAY_RT_SFIC_P.Gain_Gain_l
	  section.data(29).logicalSrcIdx = 45;
	  section.data(29).dtTransOffset = 32;
	
	  ;% SEGWAY_RT_SFIC_P.UnitDelay_InitialCondition_d
	  section.data(30).logicalSrcIdx = 46;
	  section.data(30).dtTransOffset = 33;
	
	  ;% SEGWAY_RT_SFIC_P.Switch_Threshold
	  section.data(31).logicalSrcIdx = 47;
	  section.data(31).dtTransOffset = 34;
	
	  ;% SEGWAY_RT_SFIC_P.Saturation_UpperSat
	  section.data(32).logicalSrcIdx = 48;
	  section.data(32).dtTransOffset = 35;
	
	  ;% SEGWAY_RT_SFIC_P.Saturation_LowerSat
	  section.data(33).logicalSrcIdx = 49;
	  section.data(33).dtTransOffset = 36;
	
	  ;% SEGWAY_RT_SFIC_P.UnitDelay_InitialCondition_dc
	  section.data(34).logicalSrcIdx = 50;
	  section.data(34).dtTransOffset = 37;
	
	  ;% SEGWAY_RT_SFIC_P.Gain_Gain_b
	  section.data(35).logicalSrcIdx = 51;
	  section.data(35).dtTransOffset = 38;
	
	  ;% SEGWAY_RT_SFIC_P.Saturation_UpperSat_j
	  section.data(36).logicalSrcIdx = 52;
	  section.data(36).dtTransOffset = 39;
	
	  ;% SEGWAY_RT_SFIC_P.Saturation_LowerSat_c
	  section.data(37).logicalSrcIdx = 53;
	  section.data(37).dtTransOffset = 40;
	
	  ;% SEGWAY_RT_SFIC_P.Constant1_Value
	  section.data(38).logicalSrcIdx = 54;
	  section.data(38).dtTransOffset = 41;
	
	  ;% SEGWAY_RT_SFIC_P.Gain_Gain_a
	  section.data(39).logicalSrcIdx = 55;
	  section.data(39).dtTransOffset = 42;
	
	  ;% SEGWAY_RT_SFIC_P.Gain3_Gain_c
	  section.data(40).logicalSrcIdx = 56;
	  section.data(40).dtTransOffset = 43;
	
	  ;% SEGWAY_RT_SFIC_P.Saturation_UpperSat_c
	  section.data(41).logicalSrcIdx = 57;
	  section.data(41).dtTransOffset = 44;
	
	  ;% SEGWAY_RT_SFIC_P.Saturation_LowerSat_m
	  section.data(42).logicalSrcIdx = 58;
	  section.data(42).dtTransOffset = 45;
	
	  ;% SEGWAY_RT_SFIC_P.Gain2_Gain_p
	  section.data(43).logicalSrcIdx = 59;
	  section.data(43).dtTransOffset = 46;
	
	  ;% SEGWAY_RT_SFIC_P.Gain1_Gain_im
	  section.data(44).logicalSrcIdx = 60;
	  section.data(44).dtTransOffset = 47;
	
	  ;% SEGWAY_RT_SFIC_P.Saturation1_UpperSat
	  section.data(45).logicalSrcIdx = 61;
	  section.data(45).dtTransOffset = 48;
	
	  ;% SEGWAY_RT_SFIC_P.Saturation1_LowerSat
	  section.data(46).logicalSrcIdx = 62;
	  section.data(46).dtTransOffset = 49;
	
	  ;% SEGWAY_RT_SFIC_P.Gain4_Gain_l
	  section.data(47).logicalSrcIdx = 63;
	  section.data(47).dtTransOffset = 50;
	
	  ;% SEGWAY_RT_SFIC_P.Delay2_InitialCondition
	  section.data(48).logicalSrcIdx = 64;
	  section.data(48).dtTransOffset = 51;
	
	  ;% SEGWAY_RT_SFIC_P.deg2rad1_Gain_d
	  section.data(49).logicalSrcIdx = 65;
	  section.data(49).dtTransOffset = 52;
	
	  ;% SEGWAY_RT_SFIC_P.deg2rad2_Gain_m
	  section.data(50).logicalSrcIdx = 66;
	  section.data(50).dtTransOffset = 53;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% SEGWAY_RT_SFIC_P.Speaker_p2
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SEGWAY_RT_SFIC_P.Speaker_p4
	  section.data(2).logicalSrcIdx = 68;
	  section.data(2).dtTransOffset = 1;
	
	  ;% SEGWAY_RT_SFIC_P.Delay2_DelayLength
	  section.data(3).logicalSrcIdx = 69;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% SEGWAY_RT_SFIC_P.Speaker_p1
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SEGWAY_RT_SFIC_P.AccelerationSensor_p1
	  section.data(2).logicalSrcIdx = 71;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
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
    nTotSects     = 3;
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
    ;% Auto data (SEGWAY_RT_SFIC_B)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% SEGWAY_RT_SFIC_B.Gain6
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SEGWAY_RT_SFIC_B.Gain1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% SEGWAY_RT_SFIC_B.Saturation
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SEGWAY_RT_SFIC_B.DataTypeConversion1
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% SEGWAY_RT_SFIC_B.Switch2
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% SEGWAY_RT_SFIC_B.Sum1
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
	  ;% SEGWAY_RT_SFIC_B.deg2rad1
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 4;
	
	  ;% SEGWAY_RT_SFIC_B.deg2rad2
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 5;
	
	  ;% SEGWAY_RT_SFIC_B.Sum
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 6;
	
	  ;% SEGWAY_RT_SFIC_B.Sum_d
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 7;
	
	  ;% SEGWAY_RT_SFIC_B.Gain3
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 8;
	
	  ;% SEGWAY_RT_SFIC_B.Sum_n
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 9;
	
	  ;% SEGWAY_RT_SFIC_B.Gain3_j
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 10;
	
	  ;% SEGWAY_RT_SFIC_B.deg2rad2_a
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 11;
	
	  ;% SEGWAY_RT_SFIC_B.Sum1_m
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 12;
	
	  ;% SEGWAY_RT_SFIC_B.Gain4
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 13;
	
	  ;% SEGWAY_RT_SFIC_B.Sum_k
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% SEGWAY_RT_SFIC_B.Compare
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SEGWAY_RT_SFIC_B.Compare_k
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
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
    nTotSects     = 5;
    sectIdxOffset = 3;
    
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
    ;% Auto data (SEGWAY_RT_SFIC_DWork)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% SEGWAY_RT_SFIC_DWork.Y_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% SEGWAY_RT_SFIC_DWork.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SEGWAY_RT_SFIC_DWork.UnitDelay_DSTATE_m
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% SEGWAY_RT_SFIC_DWork.Delay2_DSTATE
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% SEGWAY_RT_SFIC_DWork.UnitDelay_DSTATE_o
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 12;
	
	  ;% SEGWAY_RT_SFIC_DWork.DiscreteTransferFcn_states
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 13;
	
	  ;% SEGWAY_RT_SFIC_DWork.UnitDelay_DSTATE_b
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 14;
	
	  ;% SEGWAY_RT_SFIC_DWork.DiscreteTransferFcn_states_n
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 15;
	
	  ;% SEGWAY_RT_SFIC_DWork.UnitDelay_DSTATE_j
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 16;
	
	  ;% SEGWAY_RT_SFIC_DWork.UnitDelay1_DSTATE
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 17;
	
	  ;% SEGWAY_RT_SFIC_DWork.UnitDelay_DSTATE_o1
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 18;
	
	  ;% SEGWAY_RT_SFIC_DWork.UnitDelay_DSTATE_f
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 19;
	
	  ;% SEGWAY_RT_SFIC_DWork.DiscreteTransferFcn_tmp
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 20;
	
	  ;% SEGWAY_RT_SFIC_DWork.DiscreteTransferFcn_tmp_c
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 21;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% SEGWAY_RT_SFIC_DWork.clockTickCounter
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% SEGWAY_RT_SFIC_DWork.Integrator_IWORK.IcNeedsLoading
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% SEGWAY_RT_SFIC_DWork.Medidasyestimaciondeestado_Subs
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SEGWAY_RT_SFIC_DWork.Audio_SubsysRanBC
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
	  ;% SEGWAY_RT_SFIC_DWork.Calculodelamediadelamedidadelgi
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 2;
	
	  ;% SEGWAY_RT_SFIC_DWork.Estimadordeestado_SubsysRanBC
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
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


  targMap.checksum0 = 642110948;
  targMap.checksum1 = 85637125;
  targMap.checksum2 = 2848722507;
  targMap.checksum3 = 3429751452;

