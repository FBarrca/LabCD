  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
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
    ;% Auto data (VELOCIDAD_COMP_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% VELOCIDAD_COMP_P.R
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% VELOCIDAD_COMP_P.Referenciavelocidad1_Vmin
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% VELOCIDAD_COMP_P.Referenciavelocidad1_T
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% VELOCIDAD_COMP_P.Detecciondesector_const
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% VELOCIDAD_COMP_P.CompareToConstant_const
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% VELOCIDAD_COMP_P.CompareToConstant1_const
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
	  ;% VELOCIDAD_COMP_P.CompareToConstant2_const
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% VELOCIDAD_COMP_P.Gain8_Gain
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% VELOCIDAD_COMP_P.Gain6_Gain
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
	  ;% VELOCIDAD_COMP_P.OFFSET_Value
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 2;
	
	  ;% VELOCIDAD_COMP_P.Gain1_Gain
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 3;
	
	  ;% VELOCIDAD_COMP_P.HitCrossing_Offset
	  section.data(5).logicalSrcIdx = 11;
	  section.data(5).dtTransOffset = 4;
	
	  ;% VELOCIDAD_COMP_P.Saturation1_UpperSat
	  section.data(6).logicalSrcIdx = 12;
	  section.data(6).dtTransOffset = 5;
	
	  ;% VELOCIDAD_COMP_P.Saturation1_LowerSat
	  section.data(7).logicalSrcIdx = 13;
	  section.data(7).dtTransOffset = 6;
	
	  ;% VELOCIDAD_COMP_P.Gain3_Gain
	  section.data(8).logicalSrcIdx = 14;
	  section.data(8).dtTransOffset = 7;
	
	  ;% VELOCIDAD_COMP_P.Saturation_UpperSat
	  section.data(9).logicalSrcIdx = 15;
	  section.data(9).dtTransOffset = 8;
	
	  ;% VELOCIDAD_COMP_P.Saturation_LowerSat
	  section.data(10).logicalSrcIdx = 16;
	  section.data(10).dtTransOffset = 9;
	
	  ;% VELOCIDAD_COMP_P.Gain1_Gain_l
	  section.data(11).logicalSrcIdx = 17;
	  section.data(11).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 34;
      section.data(34)  = dumData; %prealloc
      
	  ;% VELOCIDAD_COMP_P.UnitDelay_InitialCondition
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% VELOCIDAD_COMP_P.Switch_Threshold
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
	  ;% VELOCIDAD_COMP_P.Saturation_UpperSat_b
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 2;
	
	  ;% VELOCIDAD_COMP_P.Saturation_LowerSat_i
	  section.data(4).logicalSrcIdx = 21;
	  section.data(4).dtTransOffset = 3;
	
	  ;% VELOCIDAD_COMP_P.DiscreteTimeIntegrator_gainval
	  section.data(5).logicalSrcIdx = 22;
	  section.data(5).dtTransOffset = 4;
	
	  ;% VELOCIDAD_COMP_P.DiscreteTimeIntegrator_IC
	  section.data(6).logicalSrcIdx = 23;
	  section.data(6).dtTransOffset = 5;
	
	  ;% VELOCIDAD_COMP_P.ang_refmaximo4_Value
	  section.data(7).logicalSrcIdx = 24;
	  section.data(7).dtTransOffset = 6;
	
	  ;% VELOCIDAD_COMP_P.Crdz_NumCoef
	  section.data(8).logicalSrcIdx = 25;
	  section.data(8).dtTransOffset = 7;
	
	  ;% VELOCIDAD_COMP_P.Crdz_DenCoef
	  section.data(9).logicalSrcIdx = 26;
	  section.data(9).dtTransOffset = 10;
	
	  ;% VELOCIDAD_COMP_P.Crdz_InitialStates
	  section.data(10).logicalSrcIdx = 27;
	  section.data(10).dtTransOffset = 13;
	
	  ;% VELOCIDAD_COMP_P.UnitDelay_InitialCondition_f
	  section.data(11).logicalSrcIdx = 28;
	  section.data(11).dtTransOffset = 14;
	
	  ;% VELOCIDAD_COMP_P.Radio1_Gain
	  section.data(12).logicalSrcIdx = 29;
	  section.data(12).dtTransOffset = 15;
	
	  ;% VELOCIDAD_COMP_P.Pasoarads_Gain
	  section.data(13).logicalSrcIdx = 30;
	  section.data(13).dtTransOffset = 16;
	
	  ;% VELOCIDAD_COMP_P.DiscreteTransferFcn_NumCoef
	  section.data(14).logicalSrcIdx = 31;
	  section.data(14).dtTransOffset = 17;
	
	  ;% VELOCIDAD_COMP_P.DiscreteTransferFcn_DenCoef
	  section.data(15).logicalSrcIdx = 32;
	  section.data(15).dtTransOffset = 19;
	
	  ;% VELOCIDAD_COMP_P.DiscreteTransferFcn_InitialStat
	  section.data(16).logicalSrcIdx = 33;
	  section.data(16).dtTransOffset = 21;
	
	  ;% VELOCIDAD_COMP_P.UnitDelay_InitialCondition_p
	  section.data(17).logicalSrcIdx = 34;
	  section.data(17).dtTransOffset = 22;
	
	  ;% VELOCIDAD_COMP_P.Radio1_Gain_d
	  section.data(18).logicalSrcIdx = 35;
	  section.data(18).dtTransOffset = 23;
	
	  ;% VELOCIDAD_COMP_P.Pasoarads_Gain_a
	  section.data(19).logicalSrcIdx = 36;
	  section.data(19).dtTransOffset = 24;
	
	  ;% VELOCIDAD_COMP_P.DiscreteTransferFcn_NumCoef_m
	  section.data(20).logicalSrcIdx = 37;
	  section.data(20).dtTransOffset = 25;
	
	  ;% VELOCIDAD_COMP_P.DiscreteTransferFcn_DenCoef_a
	  section.data(21).logicalSrcIdx = 38;
	  section.data(21).dtTransOffset = 27;
	
	  ;% VELOCIDAD_COMP_P.DiscreteTransferFcn_InitialSt_p
	  section.data(22).logicalSrcIdx = 39;
	  section.data(22).dtTransOffset = 29;
	
	  ;% VELOCIDAD_COMP_P.Media_Gain
	  section.data(23).logicalSrcIdx = 40;
	  section.data(23).dtTransOffset = 30;
	
	  ;% VELOCIDAD_COMP_P.Cdz_NumCoef
	  section.data(24).logicalSrcIdx = 41;
	  section.data(24).dtTransOffset = 31;
	
	  ;% VELOCIDAD_COMP_P.Cdz_DenCoef
	  section.data(25).logicalSrcIdx = 42;
	  section.data(25).dtTransOffset = 34;
	
	  ;% VELOCIDAD_COMP_P.Cdz_InitialStates
	  section.data(26).logicalSrcIdx = 43;
	  section.data(26).dtTransOffset = 37;
	
	  ;% VELOCIDAD_COMP_P.UnitDelay_InitialCondition_f2
	  section.data(27).logicalSrcIdx = 44;
	  section.data(27).dtTransOffset = 38;
	
	  ;% VELOCIDAD_COMP_P.RateTransition_X0
	  section.data(28).logicalSrcIdx = 45;
	  section.data(28).dtTransOffset = 39;
	
	  ;% VELOCIDAD_COMP_P.UnitDelay_InitialCondition_h
	  section.data(29).logicalSrcIdx = 46;
	  section.data(29).dtTransOffset = 40;
	
	  ;% VELOCIDAD_COMP_P.UnitDelay1_InitialCondition
	  section.data(30).logicalSrcIdx = 47;
	  section.data(30).dtTransOffset = 41;
	
	  ;% VELOCIDAD_COMP_P.Gain2_Gain
	  section.data(31).logicalSrcIdx = 48;
	  section.data(31).dtTransOffset = 42;
	
	  ;% VELOCIDAD_COMP_P.UnitDelay2_InitialCondition
	  section.data(32).logicalSrcIdx = 49;
	  section.data(32).dtTransOffset = 43;
	
	  ;% VELOCIDAD_COMP_P.Gain1_Gain_n
	  section.data(33).logicalSrcIdx = 50;
	  section.data(33).dtTransOffset = 44;
	
	  ;% VELOCIDAD_COMP_P.Gain3_Gain_p
	  section.data(34).logicalSrcIdx = 51;
	  section.data(34).dtTransOffset = 45;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% VELOCIDAD_COMP_P.UnitDelay_InitialCondition_a
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
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
    nTotSects     = 4;
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
    ;% Auto data (VELOCIDAD_COMP_B)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% VELOCIDAD_COMP_B.Gain6
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% VELOCIDAD_COMP_B.Integrator
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% VELOCIDAD_COMP_B.DataTypeConversion4
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% VELOCIDAD_COMP_B.Gain1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% VELOCIDAD_COMP_B.Saturation
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% VELOCIDAD_COMP_B.DiscreteTimeIntegrator
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% VELOCIDAD_COMP_B.Sum
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% VELOCIDAD_COMP_B.Multiply1
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
	  ;% VELOCIDAD_COMP_B.DataTypeConversion
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 4;
	
	  ;% VELOCIDAD_COMP_B.Radio
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 5;
	
	  ;% VELOCIDAD_COMP_B.DataTypeConversion1
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 6;
	
	  ;% VELOCIDAD_COMP_B.Radio_l
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 7;
	
	  ;% VELOCIDAD_COMP_B.Media
	  section.data(9).logicalSrcIdx = 12;
	  section.data(9).dtTransOffset = 8;
	
	  ;% VELOCIDAD_COMP_B.Multiply
	  section.data(10).logicalSrcIdx = 13;
	  section.data(10).dtTransOffset = 9;
	
	  ;% VELOCIDAD_COMP_B.Switch2
	  section.data(11).logicalSrcIdx = 14;
	  section.data(11).dtTransOffset = 10;
	
	  ;% VELOCIDAD_COMP_B.Sum1
	  section.data(12).logicalSrcIdx = 15;
	  section.data(12).dtTransOffset = 11;
	
	  ;% VELOCIDAD_COMP_B.RateTransition
	  section.data(13).logicalSrcIdx = 16;
	  section.data(13).dtTransOffset = 12;
	
	  ;% VELOCIDAD_COMP_B.DataTypeConversion1_d
	  section.data(14).logicalSrcIdx = 17;
	  section.data(14).dtTransOffset = 13;
	
	  ;% VELOCIDAD_COMP_B.Gain2
	  section.data(15).logicalSrcIdx = 18;
	  section.data(15).dtTransOffset = 14;
	
	  ;% VELOCIDAD_COMP_B.Gain3
	  section.data(16).logicalSrcIdx = 19;
	  section.data(16).dtTransOffset = 15;
	
	  ;% VELOCIDAD_COMP_B.Sum3
	  section.data(17).logicalSrcIdx = 20;
	  section.data(17).dtTransOffset = 16;
	
	  ;% VELOCIDAD_COMP_B.Sum1_b
	  section.data(18).logicalSrcIdx = 21;
	  section.data(18).dtTransOffset = 17;
	
	  ;% VELOCIDAD_COMP_B.Sum2
	  section.data(19).logicalSrcIdx = 22;
	  section.data(19).dtTransOffset = 18;
	
	  ;% VELOCIDAD_COMP_B.Sum4
	  section.data(20).logicalSrcIdx = 23;
	  section.data(20).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% VELOCIDAD_COMP_B.UnitDelay
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% VELOCIDAD_COMP_B.Compare
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% VELOCIDAD_COMP_B.HitCrossing
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
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
    nTotSects     = 6;
    sectIdxOffset = 4;
    
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
    ;% Auto data (VELOCIDAD_COMP_DWork)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% VELOCIDAD_COMP_DWork.Velocidad_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% VELOCIDAD_COMP_DWork.estado_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% VELOCIDAD_COMP_DWork.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% VELOCIDAD_COMP_DWork.DiscreteTimeIntegrator_DSTATE
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% VELOCIDAD_COMP_DWork.Crdz_states
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_h
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 4;
	
	  ;% VELOCIDAD_COMP_DWork.DiscreteTransferFcn_states
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 5;
	
	  ;% VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_e
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 6;
	
	  ;% VELOCIDAD_COMP_DWork.DiscreteTransferFcn_states_h
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 7;
	
	  ;% VELOCIDAD_COMP_DWork.Cdz_states
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 8;
	
	  ;% VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_d
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 10;
	
	  ;% VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_p
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 11;
	
	  ;% VELOCIDAD_COMP_DWork.UnitDelay1_DSTATE
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 12;
	
	  ;% VELOCIDAD_COMP_DWork.UnitDelay2_DSTATE
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 13;
	
	  ;% VELOCIDAD_COMP_DWork.Crdz_tmp
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 14;
	
	  ;% VELOCIDAD_COMP_DWork.DiscreteTransferFcn_tmp
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 15;
	
	  ;% VELOCIDAD_COMP_DWork.DiscreteTransferFcn_tmp_e
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 16;
	
	  ;% VELOCIDAD_COMP_DWork.Cdz_tmp
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 17;
	
	  ;% VELOCIDAD_COMP_DWork.RateTransition_Buffer0
	  section.data(17).logicalSrcIdx = 18;
	  section.data(17).dtTransOffset = 18;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% VELOCIDAD_COMP_DWork.Integrator_IWORK.IcNeedsLoading
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% VELOCIDAD_COMP_DWork.HitCrossing_MODE
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_n
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% VELOCIDAD_COMP_DWork.DiscreteTimeIntegrator_PrevRese
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% VELOCIDAD_COMP_DWork.DiscreteTimeIntegrator_SYSTEM_E
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
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


  targMap.checksum0 = 2632590607;
  targMap.checksum1 = 3999490651;
  targMap.checksum2 = 3896188434;
  targMap.checksum3 = 4034353658;

