file(REMOVE_RECURSE
  "libio_utils.pdb"
  "libio_utils.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/io_utils.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
