#!/bin/bash

# List all /dev/ttyUSB* ports
ports=$(ls /dev/ttyUSB* 2>/dev/null)

# Baudrates to try (bạn có thể chỉnh thêm nếu cần)
baudrates=(9600 115200 921600)

echo "=== Detecting AT command port for SLM310-G ==="
echo

for port in $ports; do
    for baud in "${baudrates[@]}"; do
        echo "Testing $port at baudrate $baud ..."

        # Send AT, wait for response
        response=$(timeout 2s bash -c "echo -e 'AT\r' > $port; sleep 0.5; cat $port & sleep 1; kill \$!")

        # Check if response contains OK
        if echo "$response" | grep -q "OK"; then
            echo ">>> Found AT command port: $port at $baud baud <<<"
            echo "Response:"
            echo "$response"
            echo "========================================="
        else
            echo "No OK response on $port at $baud baud."
        fi

        echo
    done
done

echo "=== Detection finished ==="
