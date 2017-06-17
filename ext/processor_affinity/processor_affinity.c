#include <ruby.h>

#ifdef linux

#include <sched.h>
#include <unistd.h>

static VALUE _get_affinity(VALUE self) {
	cpu_set_t mask;
	VALUE cpu_ids, v;
	int total, i;

	CPU_ZERO(&mask);
	if(sched_getaffinity(getpid(), sizeof(mask), &mask) == -1) {
		return Qnil;
	}

	cpu_ids = rb_ary_new2(CPU_COUNT(&mask));
	total = (int)sysconf(_SC_NPROCESSORS_ONLN);

	for(i = 0; i < total; i++) {
		if(CPU_ISSET(i, &mask) != 0) {
			v = INT2NUM(i);
			rb_ary_push(cpu_ids, v);
		}
	}

	return cpu_ids;
}

static VALUE _set_affinity(VALUE self, VALUE _cpu_ids) {
	int cpu_id;
	VALUE v;
	cpu_set_t mask;

	CPU_ZERO(&mask);

	while((v = rb_ary_shift(_cpu_ids)) != Qnil) {
		cpu_id = NUM2INT(v);
		CPU_SET(cpu_id, &mask);
	}

	if(sched_setaffinity(getpid(), sizeof(mask), &mask ) == -1) {
		return Qfalse;
	}
	return Qtrue;
}

#else

static VALUE _get_affinity(VALUE self) {
	return Qnil;
}

static VALUE _set_affinity(VALUE self, VALUE _cpu_ids) {
	return Qfalse;
}

#endif

void Init_processor_affinity() {
	VALUE m = rb_define_module("ProcessorAffinity");
	rb_define_module_function(m, "set", _set_affinity, -2);
	rb_define_module_function(m, "get", _get_affinity, 0);
}
