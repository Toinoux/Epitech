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
  Frame Cube {
    FrameTransformMatrix {
       0.200000, 0.000000, 0.000000, 0.000000,
       0.000000, 0.200000, 0.000000, 0.000000,
       0.000000, 0.000000, 0.200000, 0.000000,
      -0.387827,-0.002277, 3.559051, 1.000000;;
    }
    Mesh { // Cube mesh
      24;
      -1.000000;-1.000000;-1.000000;,
      -1.000000;-1.000000; 1.000000;,
      -1.000000; 1.000000; 1.000000;,
      -1.000000; 1.000000;-1.000000;,
      -1.000000; 1.000000;-1.000000;,
      -1.000000; 1.000000; 1.000000;,
       1.000000; 1.000000; 1.000000;,
       1.000000; 1.000000;-1.000000;,
       1.000000; 1.000000;-1.000000;,
       1.000000; 1.000000; 1.000000;,
       1.000000;-1.000000; 1.000000;,
       1.000000;-1.000000;-1.000000;,
       1.000000;-1.000000;-1.000000;,
       1.000000;-1.000000; 1.000000;,
      -1.000000;-1.000000; 1.000000;,
      -1.000000;-1.000000;-1.000000;,
      -1.000000; 1.000000;-1.000000;,
       1.000000; 1.000000;-1.000000;,
       1.000000;-1.000000;-1.000000;,
      -1.000000;-1.000000;-1.000000;,
       1.000000; 1.000000; 1.000000;,
      -1.000000; 1.000000; 1.000000;,
      -1.000000;-1.000000; 1.000000;,
       1.000000;-1.000000; 1.000000;;
      6;
      4;3,2,1,0;,
      4;7,6,5,4;,
      4;11,10,9,8;,
      4;15,14,13,12;,
      4;19,18,17,16;,
      4;23,22,21,20;;
      MeshNormals { // Cube normals
        6;
        -1.000000;-0.000000; 0.000000;,
         0.000000; 1.000000; 0.000000;,
         1.000000;-0.000000; 0.000000;,
         0.000000;-1.000000; 0.000000;,
         0.000000; 0.000000;-1.000000;,
         0.000000;-0.000000; 1.000000;;
        6;
        4;0,0,0,0;,
        4;1,1,1,1;,
        4;2,2,2,2;,
        4;3,3,3,3;,
        4;4,4,4,4;,
        4;5,5,5,5;;
      } // End of Cube normals
      MeshTextureCoords { // Cube UV coordinates
        24;
         0.093667; 0.910560;,
         0.077506; 0.103996;,
         0.887202; 0.098880;,
         0.885296; 0.902313;,
         0.885296; 0.902313;,
         0.887202; 0.098880;,
         1.000000; 0.000000;,
         0.994580; 0.989430;,
         0.994580; 0.989430;,
         1.000000; 0.000000;,
         0.000000; 0.005818;,
         0.021992; 1.000000;,
         0.021992; 1.000000;,
         0.000000; 0.005818;,
         0.077506; 0.103996;,
         0.093667; 0.910560;,
         0.885296; 0.902313;,
         0.994580; 0.989430;,
         0.021992; 1.000000;,
         0.093667; 0.910560;,
         1.000000; 0.000000;,
         0.887202; 0.098880;,
         0.077506; 0.103996;,
         0.000000; 0.005818;;
      } // End of Cube UV coordinates
      MeshMaterialList { // Cube material list
        1;
        6;
        0,
        0,
        0,
        0,
        0,
        0;;
        Material Material_010 {
           0.640000; 0.640000; 0.640000; 1.000000;;
           96.078431;
           0.500000; 0.500000; 0.500000;;
           0.000000; 0.000000; 0.000000;;
          TextureFilename {"Back_play.png";}
        }
      } // End of Cube material list
    } // End of Cube mesh
  } // End of Cube
  Frame Cube_001 {
    FrameTransformMatrix {
       0.200000, 0.000000, 0.000000, 0.000000,
       0.000000, 0.200000, 0.000000, 0.000000,
       0.000000, 0.000000, 0.200000, 0.000000,
      -0.406836, 2.161884, 3.556188, 1.000000;;
    }
    Mesh { // Cube_001 mesh
      24;
      -1.000000;-1.000000;-1.000000;,
      -1.000000;-1.000000; 1.000000;,
      -1.000000; 1.000000; 1.000000;,
      -1.000000; 1.000000;-1.000000;,
      -1.000000; 1.000000;-1.000000;,
      -1.000000; 1.000000; 1.000000;,
       1.000000; 1.000000; 1.000000;,
       1.000000; 1.000000;-1.000000;,
       1.000000; 1.000000;-1.000000;,
       1.000000; 1.000000; 1.000000;,
       1.000000;-1.000000; 1.000000;,
       1.000000;-1.000000;-1.000000;,
       1.000000;-1.000000;-1.000000;,
       1.000000;-1.000000; 1.000000;,
      -1.000000;-1.000000; 1.000000;,
      -1.000000;-1.000000;-1.000000;,
      -1.000000; 1.000000;-1.000000;,
       1.000000; 1.000000;-1.000000;,
       1.000000;-1.000000;-1.000000;,
      -1.000000;-1.000000;-1.000000;,
       1.000000; 1.000000; 1.000000;,
      -1.000000; 1.000000; 1.000000;,
      -1.000000;-1.000000; 1.000000;,
       1.000000;-1.000000; 1.000000;;
      6;
      4;3,2,1,0;,
      4;7,6,5,4;,
      4;11,10,9,8;,
      4;15,14,13,12;,
      4;19,18,17,16;,
      4;23,22,21,20;;
      MeshNormals { // Cube_001 normals
        6;
        -1.000000;-0.000000; 0.000000;,
         0.000000; 1.000000; 0.000000;,
         1.000000;-0.000000; 0.000000;,
         0.000000;-1.000000; 0.000000;,
         0.000000; 0.000000;-1.000000;,
         0.000000;-0.000000; 1.000000;;
        6;
        4;0,0,0,0;,
        4;1,1,1,1;,
        4;2,2,2,2;,
        4;3,3,3,3;,
        4;4,4,4,4;,
        4;5,5,5,5;;
      } // End of Cube_001 normals
      MeshTextureCoords { // Cube_001 UV coordinates
        24;
         0.024771; 0.900024;,
         0.022134; 0.135956;,
         0.793456; 0.124322;,
         0.770781; 0.898117;,
         0.770781; 0.898117;,
         0.793456; 0.124322;,
         1.000000; 0.000000;,
         0.962161; 0.999120;,
         0.962161; 0.999120;,
         1.000000; 0.000000;,
         0.000000; 0.017038;,
         0.004295; 1.000000;,
         0.004295; 1.000000;,
         0.000000; 0.017038;,
         0.022134; 0.135956;,
         0.024771; 0.900024;,
         0.770781; 0.898117;,
         0.962161; 0.999120;,
         0.004295; 1.000000;,
         0.024771; 0.900024;,
         1.000000; 0.000000;,
         0.793456; 0.124322;,
         0.022134; 0.135956;,
         0.000000; 0.017038;;
      } // End of Cube_001 UV coordinates
      MeshMaterialList { // Cube_001 material list
        1;
        6;
        0,
        0,
        0,
        0,
        0,
        0;;
        Material Material_010 {
           0.640000; 0.640000; 0.640000; 1.000000;;
           96.078431;
           0.500000; 0.500000; 0.500000;;
           0.000000; 0.000000; 0.000000;;
          TextureFilename {"Back_play.png";}
        }
      } // End of Cube_001 material list
    } // End of Cube_001 mesh
  } // End of Cube_001
  Frame Cube_002 {
    FrameTransformMatrix {
       0.200000, 0.000000, 0.000000, 0.000000,
       0.000000, 0.200000, 0.000000, 0.000000,
       0.000000, 0.000000, 0.200000, 0.000000,
      -0.406836, 4.272598, 3.556188, 1.000000;;
    }
    Mesh { // Cube_002 mesh
      24;
      -1.000000;-1.000000;-1.000000;,
      -1.000000;-1.000000; 1.000000;,
      -1.000000; 1.000000; 1.000000;,
      -1.000000; 1.000000;-1.000000;,
      -1.000000; 1.000000;-1.000000;,
      -1.000000; 1.000000; 1.000000;,
       1.000000; 1.000000; 1.000000;,
       1.000000; 1.000000;-1.000000;,
       1.000000; 1.000000;-1.000000;,
       1.000000; 1.000000; 1.000000;,
       1.000000;-1.000000; 1.000000;,
       1.000000;-1.000000;-1.000000;,
       1.000000;-1.000000;-1.000000;,
       1.000000;-1.000000; 1.000000;,
      -1.000000;-1.000000; 1.000000;,
      -1.000000;-1.000000;-1.000000;,
      -1.000000; 1.000000;-1.000000;,
       1.000000; 1.000000;-1.000000;,
       1.000000;-1.000000;-1.000000;,
      -1.000000;-1.000000;-1.000000;,
       1.000000; 1.000000; 1.000000;,
      -1.000000; 1.000000; 1.000000;,
      -1.000000;-1.000000; 1.000000;,
       1.000000;-1.000000; 1.000000;;
      6;
      4;3,2,1,0;,
      4;7,6,5,4;,
      4;11,10,9,8;,
      4;15,14,13,12;,
      4;19,18,17,16;,
      4;23,22,21,20;;
      MeshNormals { // Cube_002 normals
        6;
        -1.000000;-0.000000; 0.000000;,
         0.000000; 1.000000; 0.000000;,
         1.000000;-0.000000; 0.000000;,
         0.000000;-1.000000; 0.000000;,
         0.000000; 0.000000;-1.000000;,
         0.000000;-0.000000; 1.000000;;
        6;
        4;0,0,0,0;,
        4;1,1,1,1;,
        4;2,2,2,2;,
        4;3,3,3,3;,
        4;4,4,4,4;,
        4;5,5,5,5;;
      } // End of Cube_002 normals
      MeshTextureCoords { // Cube_002 UV coordinates
        24;
         0.147707; 0.901106;,
         0.136296; 0.145051;,
         0.905622; 0.131159;,
         0.897506; 0.900674;,
         0.897506; 0.900674;,
         0.905622; 0.131159;,
         1.000000; 0.000000;,
         0.986369; 1.000000;,
         0.986369; 1.000000;,
         1.000000; 0.000000;,
         0.000000; 0.020993;,
         0.019113; 0.998377;,
         0.019113; 0.998377;,
         0.000000; 0.020993;,
         0.136296; 0.145051;,
         0.147707; 0.901106;,
         0.897506; 0.900674;,
         0.986369; 1.000000;,
         0.019113; 0.998377;,
         0.147707; 0.901106;,
         1.000000; 0.000000;,
         0.905622; 0.131159;,
         0.136296; 0.145051;,
         0.000000; 0.020993;;
      } // End of Cube_002 UV coordinates
      MeshMaterialList { // Cube_002 material list
        1;
        6;
        0,
        0,
        0,
        0,
        0,
        0;;
        Material Material_010 {
           0.640000; 0.640000; 0.640000; 1.000000;;
           96.078431;
           0.500000; 0.500000; 0.500000;;
           0.000000; 0.000000; 0.000000;;
          TextureFilename {"Back_play.png";}
        }
      } // End of Cube_002 material list
    } // End of Cube_002 mesh
  } // End of Cube_002
  Frame Cube_003 {
    FrameTransformMatrix {
       0.200000, 0.000000, 0.000000, 0.000000,
       0.000000, 0.200000, 0.000000, 0.000000,
       0.000000, 0.000000, 0.200000, 0.000000,
      -0.406836, 6.395113, 3.556188, 1.000000;;
    }
    Mesh { // Cube_003 mesh
      24;
      -1.000000;-1.000000;-1.000000;,
      -1.000000;-1.000000; 1.000000;,
      -1.000000; 1.000000; 1.000000;,
      -1.000000; 1.000000;-1.000000;,
      -1.000000; 1.000000;-1.000000;,
      -1.000000; 1.000000; 1.000000;,
       1.000000; 1.000000; 1.000000;,
       1.000000; 1.000000;-1.000000;,
       1.000000; 1.000000;-1.000000;,
       1.000000; 1.000000; 1.000000;,
       1.000000;-1.000000; 1.000000;,
       1.000000;-1.000000;-1.000000;,
       1.000000;-1.000000;-1.000000;,
       1.000000;-1.000000; 1.000000;,
      -1.000000;-1.000000; 1.000000;,
      -1.000000;-1.000000;-1.000000;,
      -1.000000; 1.000000;-1.000000;,
       1.000000; 1.000000;-1.000000;,
       1.000000;-1.000000;-1.000000;,
      -1.000000;-1.000000;-1.000000;,
       1.000000; 1.000000; 1.000000;,
      -1.000000; 1.000000; 1.000000;,
      -1.000000;-1.000000; 1.000000;,
       1.000000;-1.000000; 1.000000;;
      6;
      4;3,2,1,0;,
      4;7,6,5,4;,
      4;11,10,9,8;,
      4;15,14,13,12;,
      4;19,18,17,16;,
      4;23,22,21,20;;
      MeshNormals { // Cube_003 normals
        6;
        -1.000000;-0.000000; 0.000000;,
         0.000000; 1.000000; 0.000000;,
         1.000000;-0.000000; 0.000000;,
         0.000000;-1.000000; 0.000000;,
         0.000000; 0.000000;-1.000000;,
         0.000000;-0.000000; 1.000000;;
        6;
        4;0,0,0,0;,
        4;1,1,1,1;,
        4;2,2,2,2;,
        4;3,3,3,3;,
        4;4,4,4,4;,
        4;5,5,5,5;;
      } // End of Cube_003 normals
      MeshTextureCoords { // Cube_003 UV coordinates
        24;
         0.048360; 0.916362;,
         0.044438; 0.165120;,
         0.808122; 0.150227;,
         0.794651; 0.915094;,
         0.794651; 0.915094;,
         0.808122; 0.150227;,
         1.000000; 0.000000;,
         0.976756; 1.000000;,
         0.976756; 1.000000;,
         1.000000; 0.000000;,
         0.000000; 0.022894;,
         0.006370; 0.999731;,
         0.006370; 0.999731;,
         0.000000; 0.022894;,
         0.044438; 0.165120;,
         0.048360; 0.916362;,
         0.794651; 0.915094;,
         0.976756; 1.000000;,
         0.006370; 0.999731;,
         0.048360; 0.916362;,
         1.000000; 0.000000;,
         0.808122; 0.150227;,
         0.044438; 0.165120;,
         0.000000; 0.022894;;
      } // End of Cube_003 UV coordinates
      MeshMaterialList { // Cube_003 material list
        1;
        6;
        0,
        0,
        0,
        0,
        0,
        0;;
        Material Material_010 {
           0.640000; 0.640000; 0.640000; 1.000000;;
           96.078431;
           0.500000; 0.500000; 0.500000;;
           0.000000; 0.000000; 0.000000;;
          TextureFilename {"Back_play.png";}
        }
      } // End of Cube_003 material list
    } // End of Cube_003 mesh
  } // End of Cube_003
} // End of Root
AnimTicksPerSecond {
  24;
}
AnimationSet Global {
  Animation {
    {Cube}
    AnimationKey { // Rotation
      0;
      42;
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
      13;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      14;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      15;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      16;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      17;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      18;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      19;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      20;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      21;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      22;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      23;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      24;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      25;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      26;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      27;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      28;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      29;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      30;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      31;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      32;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      33;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      34;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      35;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      36;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      37;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      38;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      39;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      40;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      41;4;-1.000000, 0.000000, 0.000000, 0.000000;;;
    }
    AnimationKey { // Scale
      1;
      42;
      0;3; 0.200000, 0.200000, 0.200000;;,
      1;3; 0.200000, 0.200000, 0.200000;;,
      2;3; 0.243544, 0.243544, 0.243544;;,
      3;3; 0.329303, 0.329303, 0.329303;;,
      4;3; 0.432365, 0.432365, 0.432365;;,
      5;3; 0.543340, 0.543340, 0.543340;;,
      6;3; 0.656660, 0.656660, 0.656660;;,
      7;3; 0.767635, 0.767635, 0.767635;;,
      8;3; 0.870697, 0.870697, 0.870697;;,
      9;3; 0.956456, 0.956456, 0.956456;;,
      10;3; 1.000000, 1.000000, 1.000000;;,
      11;3; 1.000000, 1.000000, 1.000000;;,
      12;3; 1.000000, 1.000000, 1.000000;;,
      13;3; 1.000000, 1.000000, 1.000000;;,
      14;3; 1.000000, 1.000000, 1.000000;;,
      15;3; 1.000000, 1.000000, 1.000000;;,
      16;3; 1.000000, 1.000000, 1.000000;;,
      17;3; 1.000000, 1.000000, 1.000000;;,
      18;3; 1.000000, 1.000000, 1.000000;;,
      19;3; 1.000000, 1.000000, 1.000000;;,
      20;3; 1.000000, 1.000000, 1.000000;;,
      21;3; 1.000000, 1.000000, 1.000000;;,
      22;3; 1.000000, 1.000000, 1.000000;;,
      23;3; 1.000000, 1.000000, 1.000000;;,
      24;3; 1.000000, 1.000000, 1.000000;;,
      25;3; 1.000000, 1.000000, 1.000000;;,
      26;3; 1.000000, 1.000000, 1.000000;;,
      27;3; 1.000000, 1.000000, 1.000000;;,
      28;3; 1.000000, 1.000000, 1.000000;;,
      29;3; 1.000000, 1.000000, 1.000000;;,
      30;3; 1.000000, 1.000000, 1.000000;;,
      31;3; 1.000000, 1.000000, 1.000000;;,
      32;3; 1.000000, 1.000000, 1.000000;;,
      33;3; 1.000000, 1.000000, 1.000000;;,
      34;3; 1.000000, 1.000000, 1.000000;;,
      35;3; 1.000000, 1.000000, 1.000000;;,
      36;3; 1.000000, 1.000000, 1.000000;;,
      37;3; 1.000000, 1.000000, 1.000000;;,
      38;3; 1.000000, 1.000000, 1.000000;;,
      39;3; 1.000000, 1.000000, 1.000000;;,
      40;3; 1.000000, 1.000000, 1.000000;;,
      41;3; 1.000000, 1.000000, 1.000000;;;
    }
    AnimationKey { // Position
      2;
      42;
      0;3;-0.387827,-0.002277, 3.559051;;,
      1;3;-0.387827,-0.002277, 3.559051;;,
      2;3;-0.387827,-0.002277, 3.559051;;,
      3;3;-0.387827,-0.002277, 3.559051;;,
      4;3;-0.387827,-0.002277, 3.559051;;,
      5;3;-0.387827,-0.002277, 3.559051;;,
      6;3;-0.387827,-0.002277, 3.559051;;,
      7;3;-0.387827,-0.002277, 3.559051;;,
      8;3;-0.387827,-0.002277, 3.559051;;,
      9;3;-0.387827,-0.002277, 3.559051;;,
      10;3;-0.387827,-0.002277, 3.559051;;,
      11;3;-0.387827,-0.002277, 3.559051;;,
      12;3;-0.387827,-0.002277, 3.559051;;,
      13;3;-0.387827,-0.002277, 3.559051;;,
      14;3;-0.387827,-0.002277, 3.559051;;,
      15;3;-0.387827,-0.002277, 3.559051;;,
      16;3;-0.387827,-0.002277, 3.559051;;,
      17;3;-0.387827,-0.002277, 3.559051;;,
      18;3;-0.387827,-0.002277, 3.559051;;,
      19;3;-0.387827,-0.002277, 3.559051;;,
      20;3;-0.387827,-0.002277, 3.559051;;,
      21;3;-0.387827,-0.002277, 3.559051;;,
      22;3;-0.387827,-0.002277, 3.559051;;,
      23;3;-0.387827,-0.002277, 3.559051;;,
      24;3;-0.387827,-0.002277, 3.559051;;,
      25;3;-0.387827,-0.002277, 3.559051;;,
      26;3;-0.387827,-0.002277, 3.559051;;,
      27;3;-0.387827,-0.002277, 3.559051;;,
      28;3;-0.387827,-0.002277, 3.559051;;,
      29;3;-0.387827,-0.002277, 3.559051;;,
      30;3;-0.387827,-0.002277, 3.559051;;,
      31;3;-0.387827,-0.002277, 3.559051;;,
      32;3;-0.387827,-0.002277, 3.559051;;,
      33;3;-0.387827,-0.002277, 3.559051;;,
      34;3;-0.387827,-0.002277, 3.559051;;,
      35;3;-0.387827,-0.002277, 3.559051;;,
      36;3;-0.387827,-0.002277, 3.559051;;,
      37;3;-0.387827,-0.002277, 3.559051;;,
      38;3;-0.387827,-0.002277, 3.559051;;,
      39;3;-0.387827,-0.002277, 3.559051;;,
      40;3;-0.387827,-0.002277, 3.559051;;,
      41;3;-0.387827,-0.002277, 3.559051;;;
    }
  }
  Animation {
    {Cube_001}
    AnimationKey { // Rotation
      0;
      42;
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
      13;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      14;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      15;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      16;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      17;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      18;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      19;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      20;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      21;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      22;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      23;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      24;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      25;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      26;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      27;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      28;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      29;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      30;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      31;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      32;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      33;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      34;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      35;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      36;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      37;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      38;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      39;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      40;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      41;4;-1.000000, 0.000000, 0.000000, 0.000000;;;
    }
    AnimationKey { // Scale
      1;
      42;
      0;3; 0.200000, 0.200000, 0.200000;;,
      1;3; 0.200000, 0.200000, 0.200000;;,
      2;3; 0.200000, 0.200000, 0.200000;;,
      3;3; 0.200000, 0.200000, 0.200000;;,
      4;3; 0.200000, 0.200000, 0.200000;;,
      5;3; 0.200000, 0.200000, 0.200000;;,
      6;3; 0.200000, 0.200000, 0.200000;;,
      7;3; 0.200000, 0.200000, 0.200000;;,
      8;3; 0.200000, 0.200000, 0.200000;;,
      9;3; 0.200000, 0.200000, 0.200000;;,
      10;3; 0.200000, 0.200000, 0.200000;;,
      11;3; 0.200000, 0.200000, 0.200000;;,
      12;3; 0.220265, 0.220265, 0.220265;;,
      13;3; 0.276090, 0.276090, 0.276090;;,
      14;3; 0.360587, 0.360587, 0.360587;;,
      15;3; 0.467200, 0.467200, 0.467200;;,
      16;3; 0.589097, 0.589097, 0.589097;;,
      17;3; 0.718315, 0.718315, 0.718315;;,
      18;3; 0.844184, 0.844184, 0.844184;;,
      19;3; 0.949667, 0.949667, 0.949667;;,
      20;3; 1.000000, 1.000000, 1.000000;;,
      21;3; 1.000000, 1.000000, 1.000000;;,
      22;3; 1.000000, 1.000000, 1.000000;;,
      23;3; 1.000000, 1.000000, 1.000000;;,
      24;3; 1.000000, 1.000000, 1.000000;;,
      25;3; 1.000000, 1.000000, 1.000000;;,
      26;3; 1.000000, 1.000000, 1.000000;;,
      27;3; 1.000000, 1.000000, 1.000000;;,
      28;3; 1.000000, 1.000000, 1.000000;;,
      29;3; 1.000000, 1.000000, 1.000000;;,
      30;3; 1.000000, 1.000000, 1.000000;;,
      31;3; 1.000000, 1.000000, 1.000000;;,
      32;3; 1.000000, 1.000000, 1.000000;;,
      33;3; 1.000000, 1.000000, 1.000000;;,
      34;3; 1.000000, 1.000000, 1.000000;;,
      35;3; 1.000000, 1.000000, 1.000000;;,
      36;3; 1.000000, 1.000000, 1.000000;;,
      37;3; 1.000000, 1.000000, 1.000000;;,
      38;3; 1.000000, 1.000000, 1.000000;;,
      39;3; 1.000000, 1.000000, 1.000000;;,
      40;3; 1.000000, 1.000000, 1.000000;;,
      41;3; 1.000000, 1.000000, 1.000000;;;
    }
    AnimationKey { // Position
      2;
      42;
      0;3;-0.406836, 2.161884, 3.556188;;,
      1;3;-0.406836, 2.161884, 3.556188;;,
      2;3;-0.406836, 2.161884, 3.556188;;,
      3;3;-0.406836, 2.161884, 3.556188;;,
      4;3;-0.406836, 2.161884, 3.556188;;,
      5;3;-0.406836, 2.161884, 3.556188;;,
      6;3;-0.406836, 2.161884, 3.556188;;,
      7;3;-0.406836, 2.161884, 3.556188;;,
      8;3;-0.406836, 2.161884, 3.556188;;,
      9;3;-0.406836, 2.161884, 3.556188;;,
      10;3;-0.406836, 2.161884, 3.556188;;,
      11;3;-0.406836, 2.161884, 3.556188;;,
      12;3;-0.406836, 2.161884, 3.556188;;,
      13;3;-0.406836, 2.161884, 3.556188;;,
      14;3;-0.406836, 2.161884, 3.556188;;,
      15;3;-0.406836, 2.161884, 3.556188;;,
      16;3;-0.406836, 2.161884, 3.556188;;,
      17;3;-0.406836, 2.161884, 3.556188;;,
      18;3;-0.406836, 2.161884, 3.556188;;,
      19;3;-0.406836, 2.161884, 3.556188;;,
      20;3;-0.406836, 2.161884, 3.556188;;,
      21;3;-0.406836, 2.161884, 3.556188;;,
      22;3;-0.406836, 2.161884, 3.556188;;,
      23;3;-0.406836, 2.161884, 3.556188;;,
      24;3;-0.406836, 2.161884, 3.556188;;,
      25;3;-0.406836, 2.161884, 3.556188;;,
      26;3;-0.406836, 2.161884, 3.556188;;,
      27;3;-0.406836, 2.161884, 3.556188;;,
      28;3;-0.406836, 2.161884, 3.556188;;,
      29;3;-0.406836, 2.161884, 3.556188;;,
      30;3;-0.406836, 2.161884, 3.556188;;,
      31;3;-0.406836, 2.161884, 3.556188;;,
      32;3;-0.406836, 2.161884, 3.556188;;,
      33;3;-0.406836, 2.161884, 3.556188;;,
      34;3;-0.406836, 2.161884, 3.556188;;,
      35;3;-0.406836, 2.161884, 3.556188;;,
      36;3;-0.406836, 2.161884, 3.556188;;,
      37;3;-0.406836, 2.161884, 3.556188;;,
      38;3;-0.406836, 2.161884, 3.556188;;,
      39;3;-0.406836, 2.161884, 3.556188;;,
      40;3;-0.406836, 2.161884, 3.556188;;,
      41;3;-0.406836, 2.161884, 3.556188;;;
    }
  }
  Animation {
    {Cube_002}
    AnimationKey { // Rotation
      0;
      42;
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
      13;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      14;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      15;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      16;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      17;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      18;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      19;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      20;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      21;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      22;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      23;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      24;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      25;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      26;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      27;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      28;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      29;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      30;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      31;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      32;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      33;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      34;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      35;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      36;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      37;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      38;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      39;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      40;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      41;4;-1.000000, 0.000000, 0.000000, 0.000000;;;
    }
    AnimationKey { // Scale
      1;
      42;
      0;3; 0.200000, 0.200000, 0.200000;;,
      1;3; 0.200000, 0.200000, 0.200000;;,
      2;3; 0.200000, 0.200000, 0.200000;;,
      3;3; 0.200000, 0.200000, 0.200000;;,
      4;3; 0.200000, 0.200000, 0.200000;;,
      5;3; 0.200000, 0.200000, 0.200000;;,
      6;3; 0.200000, 0.200000, 0.200000;;,
      7;3; 0.200000, 0.200000, 0.200000;;,
      8;3; 0.200000, 0.200000, 0.200000;;,
      9;3; 0.200000, 0.200000, 0.200000;;,
      10;3; 0.200000, 0.200000, 0.200000;;,
      11;3; 0.200000, 0.200000, 0.200000;;,
      12;3; 0.200000, 0.200000, 0.200000;;,
      13;3; 0.200000, 0.200000, 0.200000;;,
      14;3; 0.200000, 0.200000, 0.200000;;,
      15;3; 0.200000, 0.200000, 0.200000;;,
      16;3; 0.200000, 0.200000, 0.200000;;,
      17;3; 0.200000, 0.200000, 0.200000;;,
      18;3; 0.200000, 0.200000, 0.200000;;,
      19;3; 0.200000, 0.200000, 0.200000;;,
      20;3; 0.200000, 0.200000, 0.200000;;,
      21;3; 0.200000, 0.200000, 0.200000;;,
      22;3; 0.220265, 0.220265, 0.220265;;,
      23;3; 0.276090, 0.276090, 0.276090;;,
      24;3; 0.360587, 0.360587, 0.360587;;,
      25;3; 0.467200, 0.467200, 0.467200;;,
      26;3; 0.589097, 0.589097, 0.589097;;,
      27;3; 0.718315, 0.718315, 0.718315;;,
      28;3; 0.844184, 0.844184, 0.844184;;,
      29;3; 0.949667, 0.949667, 0.949667;;,
      30;3; 1.000000, 1.000000, 1.000000;;,
      31;3; 1.000000, 1.000000, 1.000000;;,
      32;3; 1.000000, 1.000000, 1.000000;;,
      33;3; 1.000000, 1.000000, 1.000000;;,
      34;3; 1.000000, 1.000000, 1.000000;;,
      35;3; 1.000000, 1.000000, 1.000000;;,
      36;3; 1.000000, 1.000000, 1.000000;;,
      37;3; 1.000000, 1.000000, 1.000000;;,
      38;3; 1.000000, 1.000000, 1.000000;;,
      39;3; 1.000000, 1.000000, 1.000000;;,
      40;3; 1.000000, 1.000000, 1.000000;;,
      41;3; 1.000000, 1.000000, 1.000000;;;
    }
    AnimationKey { // Position
      2;
      42;
      0;3;-0.406836, 4.272598, 3.556188;;,
      1;3;-0.406836, 4.272598, 3.556188;;,
      2;3;-0.406836, 4.272598, 3.556188;;,
      3;3;-0.406836, 4.272598, 3.556188;;,
      4;3;-0.406836, 4.272598, 3.556188;;,
      5;3;-0.406836, 4.272598, 3.556188;;,
      6;3;-0.406836, 4.272598, 3.556188;;,
      7;3;-0.406836, 4.272598, 3.556188;;,
      8;3;-0.406836, 4.272598, 3.556188;;,
      9;3;-0.406836, 4.272598, 3.556188;;,
      10;3;-0.406836, 4.272598, 3.556188;;,
      11;3;-0.406836, 4.272598, 3.556188;;,
      12;3;-0.406836, 4.272598, 3.556188;;,
      13;3;-0.406836, 4.272598, 3.556188;;,
      14;3;-0.406836, 4.272598, 3.556188;;,
      15;3;-0.406836, 4.272598, 3.556188;;,
      16;3;-0.406836, 4.272598, 3.556188;;,
      17;3;-0.406836, 4.272598, 3.556188;;,
      18;3;-0.406836, 4.272598, 3.556188;;,
      19;3;-0.406836, 4.272598, 3.556188;;,
      20;3;-0.406836, 4.272598, 3.556188;;,
      21;3;-0.406836, 4.272598, 3.556188;;,
      22;3;-0.406836, 4.272598, 3.556188;;,
      23;3;-0.406836, 4.272598, 3.556188;;,
      24;3;-0.406836, 4.272598, 3.556188;;,
      25;3;-0.406836, 4.272598, 3.556188;;,
      26;3;-0.406836, 4.272598, 3.556188;;,
      27;3;-0.406836, 4.272598, 3.556188;;,
      28;3;-0.406836, 4.272598, 3.556188;;,
      29;3;-0.406836, 4.272598, 3.556188;;,
      30;3;-0.406836, 4.272598, 3.556188;;,
      31;3;-0.406836, 4.272598, 3.556188;;,
      32;3;-0.406836, 4.272598, 3.556188;;,
      33;3;-0.406836, 4.272598, 3.556188;;,
      34;3;-0.406836, 4.272598, 3.556188;;,
      35;3;-0.406836, 4.272598, 3.556188;;,
      36;3;-0.406836, 4.272598, 3.556188;;,
      37;3;-0.406836, 4.272598, 3.556188;;,
      38;3;-0.406836, 4.272598, 3.556188;;,
      39;3;-0.406836, 4.272598, 3.556188;;,
      40;3;-0.406836, 4.272598, 3.556188;;,
      41;3;-0.406836, 4.272598, 3.556188;;;
    }
  }
  Animation {
    {Cube_003}
    AnimationKey { // Rotation
      0;
      42;
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
      13;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      14;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      15;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      16;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      17;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      18;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      19;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      20;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      21;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      22;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      23;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      24;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      25;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      26;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      27;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      28;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      29;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      30;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      31;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      32;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      33;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      34;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      35;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      36;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      37;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      38;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      39;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      40;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      41;4;-1.000000, 0.000000, 0.000000, 0.000000;;;
    }
    AnimationKey { // Scale
      1;
      42;
      0;3; 0.200000, 0.200000, 0.200000;;,
      1;3; 0.200000, 0.200000, 0.200000;;,
      2;3; 0.200000, 0.200000, 0.200000;;,
      3;3; 0.200000, 0.200000, 0.200000;;,
      4;3; 0.200000, 0.200000, 0.200000;;,
      5;3; 0.200000, 0.200000, 0.200000;;,
      6;3; 0.200000, 0.200000, 0.200000;;,
      7;3; 0.200000, 0.200000, 0.200000;;,
      8;3; 0.200000, 0.200000, 0.200000;;,
      9;3; 0.200000, 0.200000, 0.200000;;,
      10;3; 0.200000, 0.200000, 0.200000;;,
      11;3; 0.200000, 0.200000, 0.200000;;,
      12;3; 0.200000, 0.200000, 0.200000;;,
      13;3; 0.200000, 0.200000, 0.200000;;,
      14;3; 0.200000, 0.200000, 0.200000;;,
      15;3; 0.200000, 0.200000, 0.200000;;,
      16;3; 0.200000, 0.200000, 0.200000;;,
      17;3; 0.200000, 0.200000, 0.200000;;,
      18;3; 0.200000, 0.200000, 0.200000;;,
      19;3; 0.200000, 0.200000, 0.200000;;,
      20;3; 0.200000, 0.200000, 0.200000;;,
      21;3; 0.200000, 0.200000, 0.200000;;,
      22;3; 0.200000, 0.200000, 0.200000;;,
      23;3; 0.200000, 0.200000, 0.200000;;,
      24;3; 0.200000, 0.200000, 0.200000;;,
      25;3; 0.200000, 0.200000, 0.200000;;,
      26;3; 0.200000, 0.200000, 0.200000;;,
      27;3; 0.200000, 0.200000, 0.200000;;,
      28;3; 0.200000, 0.200000, 0.200000;;,
      29;3; 0.200000, 0.200000, 0.200000;;,
      30;3; 0.200000, 0.200000, 0.200000;;,
      31;3; 0.200000, 0.200000, 0.200000;;,
      32;3; 0.220265, 0.220265, 0.220265;;,
      33;3; 0.276090, 0.276090, 0.276090;;,
      34;3; 0.360587, 0.360587, 0.360587;;,
      35;3; 0.467200, 0.467200, 0.467200;;,
      36;3; 0.589097, 0.589097, 0.589097;;,
      37;3; 0.718315, 0.718315, 0.718315;;,
      38;3; 0.844184, 0.844184, 0.844184;;,
      39;3; 0.949667, 0.949667, 0.949667;;,
      40;3; 1.000000, 1.000000, 1.000000;;,
      41;3; 1.000000, 1.000000, 1.000000;;;
    }
    AnimationKey { // Position
      2;
      42;
      0;3;-0.406836, 6.395113, 3.556188;;,
      1;3;-0.406836, 6.395113, 3.556188;;,
      2;3;-0.406836, 6.395113, 3.556188;;,
      3;3;-0.406836, 6.395113, 3.556188;;,
      4;3;-0.406836, 6.395113, 3.556188;;,
      5;3;-0.406836, 6.395113, 3.556188;;,
      6;3;-0.406836, 6.395113, 3.556188;;,
      7;3;-0.406836, 6.395113, 3.556188;;,
      8;3;-0.406836, 6.395113, 3.556188;;,
      9;3;-0.406836, 6.395113, 3.556188;;,
      10;3;-0.406836, 6.395113, 3.556188;;,
      11;3;-0.406836, 6.395113, 3.556188;;,
      12;3;-0.406836, 6.395113, 3.556188;;,
      13;3;-0.406836, 6.395113, 3.556188;;,
      14;3;-0.406836, 6.395113, 3.556188;;,
      15;3;-0.406836, 6.395113, 3.556188;;,
      16;3;-0.406836, 6.395113, 3.556188;;,
      17;3;-0.406836, 6.395113, 3.556188;;,
      18;3;-0.406836, 6.395113, 3.556188;;,
      19;3;-0.406836, 6.395113, 3.556188;;,
      20;3;-0.406836, 6.395113, 3.556188;;,
      21;3;-0.406836, 6.395113, 3.556188;;,
      22;3;-0.406836, 6.395113, 3.556188;;,
      23;3;-0.406836, 6.395113, 3.556188;;,
      24;3;-0.406836, 6.395113, 3.556188;;,
      25;3;-0.406836, 6.395113, 3.556188;;,
      26;3;-0.406836, 6.395113, 3.556188;;,
      27;3;-0.406836, 6.395113, 3.556188;;,
      28;3;-0.406836, 6.395113, 3.556188;;,
      29;3;-0.406836, 6.395113, 3.556188;;,
      30;3;-0.406836, 6.395113, 3.556188;;,
      31;3;-0.406836, 6.395113, 3.556188;;,
      32;3;-0.406836, 6.395113, 3.556188;;,
      33;3;-0.406836, 6.395113, 3.556188;;,
      34;3;-0.406836, 6.395113, 3.556188;;,
      35;3;-0.406836, 6.395113, 3.556188;;,
      36;3;-0.406836, 6.395113, 3.556188;;,
      37;3;-0.406836, 6.395113, 3.556188;;,
      38;3;-0.406836, 6.395113, 3.556188;;,
      39;3;-0.406836, 6.395113, 3.556188;;,
      40;3;-0.406836, 6.395113, 3.556188;;,
      41;3;-0.406836, 6.395113, 3.556188;;;
    }
  }
} // End of AnimationSet Global