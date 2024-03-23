{
  "targets": [
    {
      "target_name": "mySudokuModule",
      "sources": [
          "cpp_resources/mySudokuModule.cpp",
          "cpp_resources/opencv.cpp"
          ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "/usr/include/opencv4"
      ],
      "libraries": [
          "-L/usr/local/lib",
          "-lopencv_core",
          "-lopencv_imgproc",
          "-lopencv_highgui",
          "-lopencv_imgcodecs"
      ],
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ]
    }
  ]
}

###########################
### To build the module ###
###########################
#                         #
#   * node-gyp clean      #
#   * node-gyp configure  #
#   * node-gyp build      #
#                         #
###########################
