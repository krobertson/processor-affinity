Gem::Specification.new do |s|
  s.name        = 'processor_affinity'
  s.version     = '0.0.1'

  s.summary     = 'Set processor affinity from ruby'
  s.description = 'Enable you to easily set the processor affinity for the current process.'

  s.authors     = ['Ken Robertson']
  s.email       = ['ken@r7n.io']
  s.homepage    = 'https://github.com/krobertson/processor-affinity'
  s.license     = 'MIT'

  s.files         = `git ls-files`.split("\n")
  s.extensions  = [ 'ext/processor_affinity/extconf.rb' ]
end
