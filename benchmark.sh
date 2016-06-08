set -e
make all

echo "--------------------------------------------------------------------------------"
uptime
echo "--------------------------------------------------------------------------------"

for k in 100 200 300 400 500; do
    cpu=$(./cpu $k)
    cuda=$(./cuda $k)
    speedup=$(echo "scale=1; ${cpu} / ${cuda}" | bc)
    
    echo "cpuTime = ${cpu}s	cudaTime = ${cuda}s	speedup = ${speedup}x"
done
