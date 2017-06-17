require 'mkmf'

with_cppflags('-D_GNU_SOURCE') { true }
have_header('sched.h')
have_header('unistd.h')
create_makefile('processor_affinity')
