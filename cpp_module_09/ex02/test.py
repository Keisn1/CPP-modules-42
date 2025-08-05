import subprocess


def compare(got, want):
    if got != want:
        print(f"Error: got {got}; want {want}")


def run_pmerge_me(nbrs, expected_output):
    try:
        # Run the RPN executable with the expression
        cmd = ["./PMergeMe"]
        [cmd.append(str(nbr)) for nbr in nbrs]

        result = subprocess.run(cmd, capture_output=True, text=True)

        # Combine stdout and stderr for comparison
        output = result.stdout.strip()
        error_output = result.stderr.strip()
        if error_output:
            output = error_output

        compare(output, expected_output)
    except FileNotFoundError:
        print("Executable './PMergeMe' not found.")
    except Exception as e:
        print(f"An error occurred: {e}")


if __name__ == "__main__":
    run_pmerge_me([], "Error")
    run_pmerge_me([1], "1")
    run_pmerge_me([1, 2], "2")
    run_pmerge_me([1, 2, 1, 2], "4")
