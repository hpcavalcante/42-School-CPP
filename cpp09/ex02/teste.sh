#!/bin/bash

program="./PmergeMe"

# Função para gerar uma sequência aleatória de inteiros
generate_random_sequence() {
  seq $1 | shuf | tr '\n' ' '
}

# Função para medir o tempo de execução do programa
measure_execution_time() {
  local input_sequence=$1
  local container_type=$2
  local start_time=$(date +%s.%N)
  $program $input_sequence $container_type > /dev/null
  local end_time=$(date +%s.%N)
  local execution_time=$(echo "$end_time - $start_time" | bc -l)
  echo "Execution time with $container_type: $execution_time seconds"
}

# Configurações de teste
num_tests=5  # Número de testes para cada tamanho de dados
min_size=1000  # Tamanho mínimo do conjunto de dados
max_size=10000  # Tamanho máximo do conjunto de dados
step_size=2000  # Incremento no tamanho do conjunto de dados

# Loop para testar diferentes tamanhos de dados
for ((size=min_size; size<=max_size; size+=step_size)); do
  echo "Testing with data size: $size"
  
  # Executar o teste várias vezes para obter uma média de tempo de execução
  total_time_vector=0.0
  total_time_list=0.0
  
  for ((i=1; i<=num_tests; i++)); do
    echo "Test $i"
    
    # Gerar uma sequência aleatória de inteiros
    input_sequence=$(generate_random_sequence $size)
    
    # Medir o tempo de execução com vector
    execution_time_vector=$(measure_execution_time "$input_sequence" "vector")
    total_time_vector=$(echo "$total_time_vector + $execution_time_vector" | bc -l)
    
    # Medir o tempo de execução com list
    execution_time_list=$(measure_execution_time "$input_sequence" "list")
    total_time_list=$(echo "$total_time_list + $execution_time_list" | bc -l)
  done
  
  # Calcular a média do tempo de execução
  average_time_vector=$(echo "$total_time_vector / $num_tests" | bc -l)
  average_time_list=$(echo "$total_time_list / $num_tests" | bc -l)
  
  echo "Average execution time with vector: $average_time_vector seconds"
  echo "Average execution time with list: $average_time_list seconds"
  echo ""
done
