{
  'targets': [
    {
      'target_name': 'cpicp-module-native',
      'sources': [ 
        'src/cpicp_module.cpp', 
        'src/cpicp.cpp',
        'src/wrappers.cpp',
        'src/common/converters.cpp',
        'src/types/Point3.cpp',
        'src/types/Cloud.cpp',
        'src/workers/CloudPartitioningWorker.cpp'],
      'include_dirs': ["<!@(node -p \"require('node-addon-api').include\")"],
      'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'xcode_settings': {
        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
        'CLANG_CXX_LIBRARY': 'libc++',
        'MACOSX_DEPLOYMENT_TARGET': '10.7'
      },
      'msvs_settings': {
        'VCCLCompilerTool': { 'ExceptionHandling': 1 },
      }
    }
  ]
}