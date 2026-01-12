#!/bin/bash

# Push Swap Performance Testing Script
# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}================================================${NC}"
echo -e "${BLUE}     Push Swap Performance Tester${NC}"
echo -e "${BLUE}================================================${NC}"z
echo ""

# Check if push_swap exists
if [ ! -f "./push_swap" ]; then
    echo -e "${RED}Error: push_swap not found. Please compile first with 'make'${NC}"
    exit 1
fi

# Check if checker exists
CHECKER="./checker_linux"
if [ ! -f "$CHECKER" ]; then
    echo -e "${YELLOW}Warning: checker_linux not found. Skipping correctness checks.${NC}"
    CHECKER=""
fi

# Function to test a specific size
test_size() {
    local size=$1
    local target=$2
    local iterations=$3
    
    echo -e "\n${BLUE}Testing with $size numbers (target: < $target moves)${NC}"
    echo -e "${BLUE}Running $iterations tests...${NC}"
    
    local total=0
    local max_moves=0
    local min_moves=999999
    local passed=0
    
    for i in $(seq 1 $iterations); do
        # Generate random numbers
        ARG=$(shuf -i 0-10000 -n $size | tr '\n' ' ')
        
        # Count moves
        moves=$(./push_swap "$ARG" | wc -l)
        total=$((total + moves))
        
        # Track min/max
        if [ $moves -gt $max_moves ]; then
            max_moves=$moves
        fi
        if [ $moves -lt $min_moves ]; then
            min_moves=$moves
        fi
        
        # Check if within target
        if [ $moves -le $target ]; then
            passed=$((passed + 1))
        fi
        
        # Verify correctness if checker available
        if [ -n "$CHECKER" ]; then
            result=$(./push_swap "$ARG" | $CHECKER "$ARG")
            if [ "$result" != "OK" ]; then
                echo -e "${RED}  Test $i: FAILED - Checker returned: $result${NC}"
                continue
            fi
        fi
        
        # Show progress
        if [ $moves -le $target ]; then
            echo -e "${GREEN}  Test $i: $moves moves ✓${NC}"
        else
            echo -e "${RED}  Test $i: $moves moves ✗ (exceeded target by $((moves - target)))${NC}"
        fi
    done
    
    # Calculate statistics
    local avg=$((total / iterations))
    local pass_rate=$((passed * 100 / iterations))
    
    echo -e "\n${BLUE}Results for $size numbers:${NC}"
    echo -e "  Average: $avg moves"
    echo -e "  Min: $min_moves moves"
    echo -e "  Max: $max_moves moves"
    echo -e "  Target: < $target moves"
    
    if [ $avg -le $target ]; then
        echo -e "  ${GREEN}Status: PASSED ✓ (Pass rate: $pass_rate%)${NC}"
    else
        echo -e "  ${RED}Status: FAILED ✗ (Pass rate: $pass_rate%)${NC}"
        echo -e "  ${YELLOW}Need to improve by: $((avg - target)) moves on average${NC}"
    fi
}

# Main testing
echo -e "${YELLOW}Starting performance tests...${NC}\n"

# Test different sizes with appropriate targets
test_size 3 3 5
test_size 5 12 5
test_size 100 900 5
test_size 500 5500 3

# Summary
echo -e "\n${BLUE}================================================${NC}"
echo -e "${BLUE}     Testing Complete${NC}"
echo -e "${BLUE}================================================${NC}"
echo ""
echo -e "${YELLOW}Scoring Guide (for 42 evaluation):${NC}"
echo "  500 numbers:"
echo "    - < 5,500 moves: 5 points"
echo "    - < 7,000 moves: 4 points"
echo "    - < 8,500 moves: 3 points"
echo "    - < 10,000 moves: 2 points"
echo "    - < 11,500 moves: 1 point"
echo ""
echo "  100 numbers:"
echo "    - < 700 moves: 5 points"
echo "    - < 900 moves: 4 points"
echo "    - < 1,100 moves: 3 points"
echo "    - < 1,300 moves: 2 points"
echo "    - < 1,500 moves: 1 point"
echo ""

# Quick comparison test
echo -e "${YELLOW}Quick comparison test (single run):${NC}"
for size in 50 100 250 500; do
    ARG=$(shuf -i 0-10000 -n $size | tr '\n' ' ')
    moves=$(./push_swap "$ARG" | wc -l)
    echo "  $size numbers: $moves moves"
done

echo -e "\n${GREEN}Tip: Run this script after each optimization to track improvement!${NC}"
