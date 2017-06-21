set -e
make all

echo "--------------------------------------------------------------------------------"
uptime
echo "--------------------------------------------------------------------------------"

for k in 100 200 300 400 500; do
	cpu_output=$(./cpu $k)
    cpu=$( echo $cpu_output | awk '{print $4}' )
    cpu_total=$( echo $cpu_output | awk '{print $8}' )
    
    cuda_output=$(./cuda $k)
    cuda=$( echo $cuda_output | awk '{print $4}' )
    cuda_total=$( echo $cuda_output | awk '{print $8}' )

    speedup=$(echo "scale=1; ${cpu} / ${cuda}" | bc)
    
    echo "Sample size: ${k}\tcpuTime: ${cpu}s, ${cpu_total}s\tcudaTime: ${cuda}s, ${cuda_total}s\tspeedup: ${speedup}x"
done
