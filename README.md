# Processor Affinity

Processor Affinity is a simple gem to set the processors that the current
process is affinitized for. This means the current process will only be ran on
the specified processors.

### Usage

The gem provides a `ProcessorAffinity` module which exposes a `set` and a `get`
function.

`set` takes the CPUs that the processor should be affinitized to. It will return
`true` on success or `false` on failure.

`get` returns an array containing the list of CPUs currently affinitized. It
will return `nil` if it fails to get the list of current CPUs.

*Please note:* This gem currently only works on Linux. On any other platform,
`set` will return `false` and `get` will return `nil`. Secondly, CPUs are a
zero-based index. An 8 core system can be passed values `0` to `7`. An invalid
CPU number will result in `set` returning `false`.
