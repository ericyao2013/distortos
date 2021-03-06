#!/bin/sh

#
# file: generateKconfig.sh
#
# author: Copyright (C) 2016-2017 Kamil Szczygiel http://www.distortec.com http://www.freddiechopin.info
#
# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
# distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

set -e
set -u

if [ ${#} -ne 1 ]; then
	echo 'This script requires 1 argument!' >&2
	exit 1
fi

output="${1}"
mkdir -p "${output}"
output="$(cd "${output}" && pwd)"
output="${output#"$(pwd)/"}"
exclusions='! -name *.jinja ! -name *.metadata'

for filePattern in $(/usr/bin/find -L . -path "./${output}" -prune -o -name 'Kconfig*' ${exclusions} -exec \
		sed -n -e 's/^source "$OUTPUT\/\(.\+\)"$/\1;\1/p' \
		-e 's/^source "$OUTPUT\/\(.\+\)"\s*# pattern: \(.\+\)$/\1;\2/p' {} +)
do

file=${filePattern%;*}
pattern=${filePattern#*;}

cat > "${output}/${file}" << EOF
#
# file: ${file}
#
# Automatically generated file - do not edit!
#
# date: $(date +'%Y-%m-%d %H:%M:%S')
#

$(/usr/bin/find -L . -path "./${output}" -prune -o -name "${pattern}" ${exclusions} -printf 'source "%p"\n' | sort)
EOF

done
