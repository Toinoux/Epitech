xof 0303txt 0032

template AnimTicksPerSecond {
  <9E415A43-7BA6-4a73-8743-B73D47E88476>
  DWORD AnimTicksPerSecond;
}

Frame Root {
  FrameTransformMatrix {
     1.000000, 0.000000, 0.000000, 0.000000,
     0.000000,-0.000000, 1.000000, 0.000000,
     0.000000, 1.000000, 0.000000, 0.000000,
     0.000000, 0.000000, 0.000000, 1.000000;;
  }
  Frame Cube_cell {
    FrameTransformMatrix {
       1.000000, 0.000000, 0.000000, 0.000000,
       0.000000, 1.000000, 0.000000, 0.000000,
       0.000000, 0.000000, 1.000000, 0.000000,
      -0.516208,-0.685646, 1.665974, 1.000000;;
    }
    Mesh { // Cube_cell mesh
      40;
      -0.483792;-0.314354;-1.661190;,
      -0.483792;-0.314354; 1.145970;,
      -0.483792;-0.285293; 1.145970;,
      -0.483792;-0.259542; 1.127629;,
      -0.483792; 0.684533; 0.454336;,
      -0.483792; 0.684865;-1.661190;,
       0.516263; 0.684940;-0.258085;,
      -0.483792;-0.259542; 1.127629;,
      -0.483792;-0.285293; 1.145970;,
      -0.460759;-0.308350; 1.145970;,
      -0.243675;-0.314354; 0.995469;,
       1.515055;-0.314354;-0.258472;,
      -0.483792; 0.684533; 0.454336;,
      -0.483792;-0.259542; 1.127629;,
       0.516263; 0.684940;-0.258085;,
      -0.454819;-0.314354; 1.145970;,
      -0.460759;-0.308350; 1.145970;,
      -0.483792;-0.285293; 1.145970;,
      -0.483792;-0.314354; 1.145970;,
      -0.460759;-0.308350; 1.145970;,
      -0.454819;-0.314354; 1.145970;,
      -0.243675;-0.314354; 0.995469;,
       1.515055;-0.314354;-0.258472;,
       1.515034;-0.314354;-1.661190;,
       0.515653; 0.684970;-1.661190;,
       0.516263; 0.684940;-0.258085;,
       1.515034;-0.314354;-1.661190;,
       1.515055;-0.314354;-0.258472;,
      -0.243675;-0.314354; 0.995469;,
      -0.454819;-0.314354; 1.145970;,
      -0.483792;-0.314354; 1.145970;,
      -0.483792;-0.314354;-1.661190;,
      -0.483792; 0.684865;-1.661190;,
       0.515653; 0.684970;-1.661190;,
       1.515034;-0.314354;-1.661190;,
      -0.483792;-0.314354;-1.661190;,
      -0.483792; 0.684533; 0.454336;,
       0.516263; 0.684940;-0.258085;,
       0.515653; 0.684970;-1.661190;,
      -0.483792; 0.684865;-1.661190;;
      9;
      6;5,4,3,2,1,0;,
      6;11,10,9,8,7,6;,
      3;14,13,12;,
      4;18,17,16,15;,
      3;21,20,19;,
      4;25,24,23,22;,
      6;31,30,29,28,27,26;,
      4;35,34,33,32;,
      4;39,38,37,36;;
      MeshNormals { // Cube_cell normals
        9;
        -1.000000; 0.000000;-0.000000;,
         0.502197; 0.501671; 0.704361;,
         0.501560; 0.502326; 0.704348;,
        -0.000000; 0.000000; 1.000000;,
         0.503330; 0.498018; 0.706142;,
         0.707186; 0.707028;-0.000151;,
        -0.000000;-1.000000;-0.000000;,
         0.000000; 0.000000;-1.000000;,
        -0.000219; 1.000000; 0.000103;;
        9;
        6;0,0,0,0,0,0;,
        6;1,1,1,1,1,1;,
        3;2,2,2;,
        4;3,3,3,3;,
        3;4,4,4;,
        4;5,5,5,5;,
        6;6,6,6,6,6,6;,
        4;7,7,7,7;,
        4;8,8,8,8;;
      } // End of Cube_cell normals
      MeshTextureCoords { // Cube_cell UV coordinates
        40;
         0.000000; 0.500000;,
         0.000000; 1.000000;,
         0.003229; 1.000000;,
         0.006090; 0.996733;,
         0.110987; 0.876809;,
         0.111024; 0.500000;,
         0.000000; 1.000000;,
         0.952788; 1.000000;,
         0.978026; 0.987376;,
         1.000000; 0.965408;,
         1.000000; 0.861956;,
         0.952327; 0.047673;,
         0.048001; 0.951999;,
         1.000000; 0.952788;,
         1.000000; 0.000000;,
         0.444445; 0.648929;,
         0.445112; 0.647871;,
         0.447674; 0.643768;,
         0.444445; 0.643768;,
         0.034592; 0.965408;,
         0.138609; 0.965424;,
         0.138044; 0.861956;,
         0.952327; 1.000000;,
         0.986479; 0.047807;,
         0.034701; 1.000000;,
         0.000000; 1.000000;,
         0.222353; 0.500000;,
         0.222350; 0.749846;,
         0.417764; 0.973191;,
         0.441225; 1.000000;,
         0.444444; 1.000000;,
         0.444445; 0.500000;,
         0.555642; 0.287536;,
         0.555634; 0.465558;,
         0.666667; 0.643559;,
         0.666667; 0.287536;,
         1.000000; 0.951999;,
         1.000000; 1.000000;,
         1.000000; 0.034701;,
         0.047300; 0.987400;;
      } // End of Cube_cell UV coordinates
      MeshMaterialList { // Cube_cell material list
        1;
        9;
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0;;
        Material Material {
           0.640000; 0.640000; 0.640000; 1.000000;;
           96.078431;
           0.500000; 0.500000; 0.500000;;
           0.000000; 0.000000; 0.000000;;
        }
      } // End of Cube_cell material list
    } // End of Cube_cell mesh
  } // End of Cube_cell
  Frame Cube_cell_001 {
    FrameTransformMatrix {
       1.000000, 0.000000, 0.000000, 0.000000,
       0.000000, 1.000000, 0.000000, 0.000000,
       0.000000, 0.000000, 1.000000, 0.000000,
      -0.555969, 0.450540, 1.021402, 1.000000;;
    }
    Mesh { // Cube_cell_001 mesh
      26;
      -0.444031; 0.549460; 1.098037;,
      -0.444031;-0.400118; 1.098151;,
      -0.444031;-0.449629; 1.098120;,
       0.554556;-0.449497; 0.385993;,
       0.555181; 0.549460; 0.386166;,
      -0.444031; 0.549460; 1.098037;,
       0.555181; 0.549460; 0.386166;,
       0.555388; 0.549460;-1.016617;,
      -0.444030; 0.549460;-1.016617;,
      -0.444031;-0.449182;-1.016617;,
       0.555029;-0.449413;-1.016617;,
       0.554556;-0.449497; 0.385993;,
      -0.444031;-0.449629; 1.098120;,
       0.555388; 0.549460;-1.016617;,
       0.555029;-0.449413;-1.016617;,
      -0.444031;-0.449182;-1.016617;,
      -0.444030; 0.549460;-1.016617;,
      -0.444031;-0.449182;-1.016617;,
      -0.444031;-0.449629; 1.098120;,
      -0.444031;-0.400118; 1.098151;,
      -0.444031; 0.549460; 1.098037;,
      -0.444030; 0.549460;-1.016617;,
       0.555029;-0.449413;-1.016617;,
       0.555388; 0.549460;-1.016617;,
       0.555181; 0.549460; 0.386166;,
       0.554556;-0.449497; 0.385993;;
      6;
      5;4,3,2,1,0;,
      4;8,7,6,5;,
      4;12,11,10,9;,
      4;16,15,14,13;,
      5;21,20,19,18,17;,
      4;25,24,23,22;;
      MeshNormals { // Cube_cell_001 normals
        6;
         0.580437;-0.000218; 0.814305;,
         0.000000; 1.000000; 0.000000;,
        -0.000104;-1.000000;-0.000151;,
         0.000000; 0.000000;-1.000000;,
        -1.000000; 0.000000;-0.000000;,
         1.000000;-0.000493; 0.000242;;
        6;
        5;0,0,0,0,0;,
        4;1,1,1,1;,
        4;2,2,2,2;,
        4;3,3,3,3;,
        5;4,4,4,4,4;,
        4;5,5,5,5;;
      } // End of Cube_cell_001 normals
      MeshTextureCoords { // Cube_cell_001 UV coordinates
        26;
         0.952692; 0.095286;,
         0.047219; 0.952781;,
         0.047249; 1.000000;,
         1.000000; 1.000000;,
         1.000000; 0.047284;,
         0.000000; 0.376654;,
         0.111024; 0.249858;,
         0.111047; 0.000000;,
         0.000000; 0.000000;,
         0.977269; 0.952579;,
         0.965248; 0.034752;,
         0.000000; 1.000000;,
         0.952752; 1.000000;,
         0.444445; 0.465549;,
         0.555430; 0.465485;,
         0.555405; 0.287536;,
         0.444445; 0.287536;,
         0.111262; 0.500000;,
         0.111212; 0.876668;,
         0.116714; 0.876674;,
         0.222222; 0.876654;,
         0.222222; 0.500000;,
         1.000000; 0.034752;,
         0.965713; 0.082325;,
         0.047284; 1.000000;,
         1.000000; 1.000000;;
      } // End of Cube_cell_001 UV coordinates
      MeshMaterialList { // Cube_cell_001 material list
        1;
        6;
        0,
        0,
        0,
        0,
        0,
        0;;
        Material Material {
           0.640000; 0.640000; 0.640000; 1.000000;;
           96.078431;
           0.500000; 0.500000; 0.500000;;
           0.000000; 0.000000; 0.000000;;
        }
      } // End of Cube_cell_001 material list
    } // End of Cube_cell_001 mesh
  } // End of Cube_cell_001
  Frame Cube_cell_002 {
    FrameTransformMatrix {
       1.000000, 0.000000, 0.000000, 0.000000,
       0.000000, 1.000000, 0.000000, 0.000000,
       0.000000, 0.000000, 1.000000, 0.000000,
       0.500474, 0.200407, 0.569640, 1.000000;;
    }
    Mesh { // Cube_cell_002 mesh
      32;
       0.499526; 0.799593;-0.564855;,
       0.499526;-1.199746;-0.564855;,
      -0.499149;-0.199709;-0.564855;,
      -0.499499; 0.799593;-0.564855;,
       0.499526; 0.799593;-0.564855;,
       0.499526; 0.799593; 0.837609;,
       0.499525;-1.198417; 0.837672;,
       0.499526;-1.199766;-0.545595;,
       0.499526;-1.199746;-0.564855;,
      -0.499149;-0.199709;-0.564855;,
       0.499526;-1.199746;-0.564855;,
       0.499526;-1.199766;-0.545595;,
      -0.499962;-0.200326; 0.837835;,
      -0.499508; 0.799593; 0.837367;,
      -0.499510; 0.799593;-0.545466;,
      -0.499962;-0.200326; 0.837835;,
      -0.499510; 0.799593;-0.545466;,
      -0.499499; 0.799593;-0.564855;,
      -0.499149;-0.199709;-0.564855;,
      -0.499962;-0.200326; 0.837835;,
       0.499526;-1.199766;-0.545595;,
       0.499525;-1.198417; 0.837672;,
      -0.499962;-0.200326; 0.837835;,
      -0.499499; 0.799593;-0.564855;,
      -0.499510; 0.799593;-0.545466;,
      -0.499508; 0.799593; 0.837367;,
       0.499526; 0.799593; 0.837609;,
       0.499526; 0.799593;-0.564855;,
       0.499525;-1.198417; 0.837672;,
       0.499526; 0.799593; 0.837609;,
      -0.499508; 0.799593; 0.837367;,
      -0.499962;-0.200326; 0.837835;;
      8;
      4;3,2,1,0;,
      5;8,7,6,5,4;,
      4;12,11,10,9;,
      3;15,14,13;,
      4;19,18,17,16;,
      3;22,21,20;,
      5;27,26,25,24,23;,
      4;31,30,29,28;;
      MeshNormals { // Cube_cell_002 normals
        8;
         0.000000; 0.000000;-1.000000;,
         1.000000;-0.000000; 0.000000;,
        -0.707588;-0.706624;-0.000721;,
        -1.000000; 0.000454; 0.000002;,
        -1.000000;-0.000350;-0.000579;,
        -0.706612;-0.707601; 0.000690;,
         0.000000; 1.000000; 0.000000;,
         0.000049; 0.000177; 1.000000;;
        8;
        4;0,0,0,0;,
        5;1,1,1,1,1;,
        4;2,2,2,2;,
        3;3,3,3;,
        4;4,4,4,4;,
        3;5,5,5;,
        5;6,6,6,6,6;,
        4;7,7,7,7;;
      } // End of Cube_cell_002 normals
      MeshTextureCoords { // Cube_cell_002 UV coordinates
        32;
         0.444445; 0.643768;,
         0.666593; 0.643768;,
         0.555478; 0.465889;,
         0.444445; 0.465826;,
         0.444445; 0.500000;,
         0.444445; 0.250199;,
         0.222443; 0.250188;,
         0.222294; 0.496569;,
         0.222296; 0.500000;,
         0.034173; 0.965827;,
         0.986727; 0.965882;,
         1.000000; 0.952620;,
         1.000000; 0.000000;,
         0.047807; 0.952193;,
         1.000000; 0.952524;,
         1.000000; 0.000000;,
         0.047476; 0.952524;,
         0.047484; 0.965875;,
         1.000000; 0.965827;,
         1.000000; 0.000000;,
         0.047380; 0.952620;,
         1.000000; 0.951996;,
         1.000000; 0.000000;,
         0.111220; 0.000000;,
         0.111218; 0.003454;,
         0.111219; 0.249758;,
         0.222222; 0.249801;,
         0.222222; 0.000000;,
         0.048004; 0.951996;,
         0.047759; 0.952817;,
         1.000000; 0.952193;,
         1.000000; 0.000000;;
      } // End of Cube_cell_002 UV coordinates
      MeshMaterialList { // Cube_cell_002 material list
        1;
        8;
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0;;
        Material Material {
           0.640000; 0.640000; 0.640000; 1.000000;;
           96.078431;
           0.500000; 0.500000; 0.500000;;
           0.000000; 0.000000; 0.000000;;
        }
      } // End of Cube_cell_002 material list
    } // End of Cube_cell_002 mesh
  } // End of Cube_cell_002
  Frame Cube_cell_003 {
    FrameTransformMatrix {
       1.000000, 0.000000, 0.000000, 0.000000,
       0.000000, 1.000000, 0.000000, 0.000000,
       0.000000, 0.000000, 1.000000, 0.000000,
      -0.227819,-0.060947, 2.267693, 1.000000;;
    }
    Mesh { // Cube_cell_003 mesh
      42;
       1.227819; 1.060946; 0.544251;,
      -0.772181; 1.060947; 0.544251;,
      -0.772182;-0.907408; 0.544251;,
      -0.764651;-0.915060; 0.544251;,
      -0.740660;-0.939053; 0.544251;,
       1.227818;-0.939054; 0.544251;,
       1.227819; 1.060946; 0.544251;,
       1.227819; 1.060946;-0.858406;,
       0.227851; 1.060947;-0.857937;,
      -0.772181; 1.060947;-0.145172;,
      -0.772181; 1.060947; 0.544251;,
       0.227885; 0.061413;-0.858555;,
       1.227819; 1.060946;-0.858406;,
       1.227027;-0.939054;-0.858175;,
       0.227851; 1.060947;-0.857937;,
       1.227819; 1.060946;-0.858406;,
       0.227885; 0.061413;-0.858555;,
      -0.764651;-0.915060; 0.544251;,
      -0.772182;-0.907408; 0.544251;,
      -0.772182;-0.787632; 0.458802;,
       1.227027;-0.939054;-0.858175;,
       1.227819; 1.060946;-0.858406;,
       1.227819; 1.060946; 0.544251;,
       1.227818;-0.939054; 0.544251;,
      -0.740660;-0.939053; 0.544251;,
      -0.764651;-0.915060; 0.544251;,
      -0.772182;-0.787632; 0.458802;,
      -0.772181; 0.061116;-0.146064;,
       0.227885; 0.061413;-0.858555;,
       1.227027;-0.939054;-0.858175;,
      -0.740660;-0.939053; 0.544251;,
       1.227027;-0.939054;-0.858175;,
       1.227818;-0.939054; 0.544251;,
      -0.772181; 1.060947;-0.145172;,
      -0.772181; 0.061116;-0.146064;,
      -0.772182;-0.787632; 0.458802;,
      -0.772182;-0.907408; 0.544251;,
      -0.772181; 1.060947; 0.544251;,
      -0.772181; 1.060947;-0.145172;,
       0.227851; 1.060947;-0.857937;,
       0.227885; 0.061413;-0.858555;,
      -0.772181; 0.061116;-0.146064;;
      10;
      6;5,4,3,2,1,0;,
      5;10,9,8,7,6;,
      3;13,12,11;,
      3;16,15,14;,
      3;19,18,17;,
      4;23,22,21,20;,
      6;29,28,27,26,25,24;,
      3;32,31,30;,
      5;37,36,35,34,33;,
      4;41,40,39,38;;
      MeshNormals { // Cube_cell_003 normals
        10;
        -0.000000;-0.000000; 1.000000;,
         0.000000; 1.000000; 0.000000;,
         0.000265;-0.000116;-1.000000;,
        -0.000469; 0.000618;-1.000000;,
        -0.508219;-0.500169;-0.701102;,
         1.000000;-0.000198;-0.000282;,
        -0.501959;-0.501795;-0.704442;,
        -0.000000;-1.000000;-0.000000;,
        -1.000000; 0.000000;-0.000000;,
        -0.580325; 0.000605;-0.814385;;
        10;
        6;0,0,0,0,0,0;,
        5;1,1,1,1,1;,
        3;2,2,2;,
        3;3,3,3;,
        3;4,4,4;,
        4;5,5,5,5;,
        6;6,6,6,6,6,6;,
        3;7,7,7;,
        5;8,8,8,8,8;,
        4;9,9,9,9;;
      } // End of Cube_cell_003 normals
      MeshTextureCoords { // Cube_cell_003 UV coordinates
        42;
         0.666667; 1.000000;,
         0.666667; 0.643768;,
         0.447961; 0.643768;,
         0.447110; 0.645109;,
         0.444445; 0.649383;,
         0.444445; 1.000000;,
         0.222222; 0.500000;,
         0.222206; 0.250164;,
         0.111115; 0.250248;,
         0.000000; 0.377203;,
         0.000000; 0.500000;,
         0.000000; 1.000000;,
         0.952340; 0.999930;,
         0.952045; 0.047955;,
         1.000000; 0.047412;,
         0.047800; 1.000000;,
         1.000000; 1.000000;,
         0.070672; 0.929328;,
         0.193187; 0.929304;,
         0.191986; 0.808014;,
         0.222222; 0.249794;,
         0.444445; 0.249836;,
         0.444444; 0.000000;,
         0.222222; 0.000000;,
         0.988922; 0.952169;,
         1.000000; 0.929328;,
         1.000000; 0.808014;,
         0.952241; 0.047759;,
         0.000000; 1.000000;,
         0.952045; 1.000000;,
         0.440942; 1.000000;,
         0.222222; 0.750206;,
         0.222222; 1.000000;,
         0.222222; 0.877203;,
         0.111130; 0.877044;,
         0.016825; 0.984780;,
         0.003516; 1.000000;,
         0.222222; 1.000000;,
         0.094783; 0.952443;,
         0.047412; 1.000000;,
         1.000000; 1.000000;,
         1.000000; 0.047759;;
      } // End of Cube_cell_003 UV coordinates
      MeshMaterialList { // Cube_cell_003 material list
        1;
        10;
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0;;
        Material Material {
           0.640000; 0.640000; 0.640000; 1.000000;;
           96.078431;
           0.500000; 0.500000; 0.500000;;
           0.000000; 0.000000; 0.000000;;
        }
      } // End of Cube_cell_003 material list
    } // End of Cube_cell_003 mesh
  } // End of Cube_cell_003
} // End of Root
AnimTicksPerSecond {
  24;
}
AnimationSet Global {
  Animation {
    {Cube_cell}
    AnimationKey { // Rotation
      0;
      14;
      0;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      1;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      2;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      3;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      4;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      5;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      6;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      7;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      8;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      9;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      10;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      11;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      12;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      13;4;-1.000000, 0.000000, 0.000000, 0.000000;;;
    }
    AnimationKey { // Scale
      1;
      14;
      0;3; 1.000000, 1.000000, 1.000000;;,
      1;3; 0.986912, 0.986912, 0.986912;;,
      2;3; 0.947374, 0.947374, 0.947374;;,
      3;3; 0.881915, 0.881915, 0.881915;;,
      4;3; 0.792751, 0.792751, 0.792751;;,
      5;3; 0.684225, 0.684225, 0.684225;;,
      6;3; 0.562904, 0.562904, 0.562904;;,
      7;3; 0.437096, 0.437096, 0.437096;;,
      8;3; 0.315775, 0.315775, 0.315775;;,
      9;3; 0.207249, 0.207249, 0.207249;;,
      10;3; 0.118085, 0.118085, 0.118085;;,
      11;3; 0.052626, 0.052626, 0.052626;;,
      12;3; 0.013088, 0.013088, 0.013088;;,
      13;3; 0.000000, 0.000000, 0.000000;;;
    }
    AnimationKey { // Position
      2;
      14;
      0;3;-0.516208,-0.685646, 1.665974;;,
      1;3;-0.516208,-0.685646, 1.665974;;,
      2;3;-0.513776,-0.936512, 1.685944;;,
      3;3;-0.513679,-1.501245, 1.684066;;,
      4;3;-0.513614,-1.877093, 1.669197;;,
      5;3;-0.513550,-2.252431, 1.643453;;,
      6;3;-0.513453,-2.814480, 1.584475;;,
      7;3;-0.513388,-3.188543, 1.531605;;,
      8;3;-0.513292,-3.748683, 1.432008;;,
      9;3;-0.513228,-4.121476, 1.352104;;,
      10;3;-0.513132,-4.679714, 1.212027;;,
      11;3;-0.513068,-5.051240, 1.105181;;,
      12;3;-0.512972,-5.607583, 0.924760;;,
      13;3;-0.512908,-5.977847, 0.791064;;;
    }
  }
  Animation {
    {Cube_cell_001}
    AnimationKey { // Rotation
      0;
      14;
      0;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      1;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      2;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      3;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      4;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      5;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      6;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      7;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      8;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      9;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      10;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      11;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      12;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      13;4;-1.000000, 0.000000, 0.000000, 0.000000;;;
    }
    AnimationKey { // Scale
      1;
      14;
      0;3; 1.000000, 1.000000, 1.000000;;,
      1;3; 0.986912, 0.986912, 0.986912;;,
      2;3; 0.947374, 0.947374, 0.947374;;,
      3;3; 0.881915, 0.881915, 0.881915;;,
      4;3; 0.792751, 0.792751, 0.792751;;,
      5;3; 0.684225, 0.684225, 0.684225;;,
      6;3; 0.562904, 0.562904, 0.562904;;,
      7;3; 0.437096, 0.437096, 0.437096;;,
      8;3; 0.315775, 0.315775, 0.315775;;,
      9;3; 0.207249, 0.207249, 0.207249;;,
      10;3; 0.118085, 0.118085, 0.118085;;,
      11;3; 0.052626, 0.052626, 0.052626;;,
      12;3; 0.013088, 0.013088, 0.013088;;,
      13;3; 0.000000, 0.000000, 0.000000;;;
    }
    AnimationKey { // Position
      2;
      14;
      0;3;-0.555969, 0.450540, 1.021402;;,
      1;3;-0.555969, 0.450540, 1.021402;;,
      2;3;-0.802907, 0.463756, 1.032082;;,
      3;3;-1.373077, 0.481382, 0.978403;;,
      4;3;-1.752544, 0.493113, 0.929059;;,
      5;3;-2.131495, 0.504828, 0.868885;;,
      6;3;-2.698956, 0.522371, 0.758353;;,
      7;3;-3.076620, 0.534046, 0.671170;;,
      8;3;-3.642153, 0.551529, 0.520194;;,
      9;3;-4.018535, 0.563164, 0.406095;;,
      10;3;-4.582148, 0.580588, 0.214811;;,
      11;3;-4.957251, 0.592184, 0.073887;;,
      12;3;-5.518950, 0.609549,-0.157566;;,
      13;3;-5.892779, 0.621105,-0.325225;;;
    }
  }
  Animation {
    {Cube_cell_002}
    AnimationKey { // Rotation
      0;
      14;
      0;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      1;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      2;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      3;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      4;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      5;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      6;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      7;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      8;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      9;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      10;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      11;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      12;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      13;4;-1.000000, 0.000000, 0.000000, 0.000000;;;
    }
    AnimationKey { // Scale
      1;
      14;
      0;3; 1.000000, 1.000000, 1.000000;;,
      1;3; 0.986912, 0.986912, 0.986912;;,
      2;3; 0.947374, 0.947374, 0.947374;;,
      3;3; 0.881915, 0.881915, 0.881915;;,
      4;3; 0.792751, 0.792751, 0.792751;;,
      5;3; 0.684225, 0.684225, 0.684225;;,
      6;3; 0.562904, 0.562904, 0.562904;;,
      7;3; 0.437096, 0.437096, 0.437096;;,
      8;3; 0.315775, 0.315775, 0.315775;;,
      9;3; 0.207249, 0.207249, 0.207249;;,
      10;3; 0.118085, 0.118085, 0.118085;;,
      11;3; 0.052626, 0.052626, 0.052626;;,
      12;3; 0.013088, 0.013088, 0.013088;;,
      13;3; 0.000000, 0.000000, 0.000000;;;
    }
    AnimationKey { // Position
      2;
      14;
      0;3; 0.500474, 0.200407, 0.569640;;,
      1;3; 0.500474, 0.200407, 0.569640;;,
      2;3; 0.730328, 0.199916, 0.526230;;,
      3;3; 1.265076, 0.167300, 0.449757;;,
      4;3; 1.620969, 0.130906, 0.392687;;,
      5;3; 1.976378, 0.094562, 0.324798;;,
      6;3; 2.508586, 0.040139, 0.202711;;,
      7;3; 2.862788, 0.003919, 0.107840;;,
      8;3; 3.393188,-0.050320,-0.054651;;,
      9;3; 3.746188,-0.086418,-0.176413;;,
      10;3; 4.274786,-0.140472,-0.379172;;,
      11;3; 4.626587,-0.176447,-0.527734;;,
      12;3; 5.153391,-0.230318,-0.770623;;,
      13;3; 5.503997,-0.266171,-0.945893;;;
    }
  }
  Animation {
    {Cube_cell_003}
    AnimationKey { // Rotation
      0;
      14;
      0;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      1;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      2;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      3;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      4;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      5;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      6;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      7;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      8;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      9;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      10;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      11;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      12;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      13;4;-1.000000, 0.000000, 0.000000, 0.000000;;;
    }
    AnimationKey { // Scale
      1;
      14;
      0;3; 1.000000, 1.000000, 1.000000;;,
      1;3; 0.986912, 0.986912, 0.986912;;,
      2;3; 0.947374, 0.947374, 0.947374;;,
      3;3; 0.881915, 0.881915, 0.881915;;,
      4;3; 0.792751, 0.792751, 0.792751;;,
      5;3; 0.684225, 0.684225, 0.684225;;,
      6;3; 0.562904, 0.562904, 0.562904;;,
      7;3; 0.437096, 0.437096, 0.437096;;,
      8;3; 0.315775, 0.315775, 0.315775;;,
      9;3; 0.207249, 0.207249, 0.207249;;,
      10;3; 0.118085, 0.118085, 0.118085;;,
      11;3; 0.052626, 0.052626, 0.052626;;,
      12;3; 0.013088, 0.013088, 0.013088;;,
      13;3; 0.000000, 0.000000, 0.000000;;;
    }
    AnimationKey { // Position
      2;
      14;
      0;3;-0.227819,-0.060947, 2.267693;;,
      1;3;-0.227819,-0.060947, 2.267693;;,
      2;3;-0.221264,-0.076406, 2.614003;;,
      3;3;-0.201628,-0.099618, 3.112160;;,
      4;3;-0.188559,-0.115067, 3.430081;;,
      5;3;-0.175508,-0.130494, 3.736673;;,
      6;3;-0.155965,-0.153596, 4.175355;;,
      7;3;-0.142958,-0.168971, 4.453693;;,
      8;3;-0.123482,-0.191994, 4.850066;;,
      9;3;-0.110519,-0.207317, 5.100246;;,
      10;3;-0.091108,-0.230262, 5.454453;;,
      11;3;-0.078190,-0.245533, 5.676570;;,
      12;3;-0.058845,-0.268401, 5.988755;;,
      13;3;-0.045971,-0.283619, 6.182905;;;
    }
  }
} // End of AnimationSet Global
