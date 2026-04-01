"""
Loading Programs - Data Analysis Tool
Demonstrates package management with dependencies.
"""

import sys
import importlib
from typing import Optional, Dict, List

# Color codes for terminal output
GREEN = "\033[92m"
RED = "\033[91m"
RESET = "\033[0m"


def check_dependency(module_name: str, package_name: Optional[str] = None) -> bool:
    """Check if a module is available."""
    try:
        importlib.import_module(module_name)
        return True
    except ImportError:
        return False


def get_package_version(module_name: str) -> Optional[str]:
    """Get the version of an installed package."""
    try:
        module = importlib.import_module(module_name)
        # Common version attributes
        for attr in ['__version__', 'VERSION', 'version']:
            if hasattr(module, attr):
                return str(getattr(module, attr))
        return "unknown"
    except ImportError:
        return None


def check_dependencies() -> Dict[str, bool]:
    """Check all required dependencies and return status."""
    dependencies = {
        'pandas': 'pandas',
        'numpy': 'numpy',
        'matplotlib': 'matplotlib',
        'requests': 'requests',
    }
    
    status = {}
    for name, module in dependencies.items():
        status[name] = check_dependency(module)
    
    return status


def display_loading_status(dependencies_status: Dict[str, bool]) -> bool:
    """Display loading status of dependencies."""
    print("LOADING STATUS: Loading programs...")
    print("Checking dependencies:")
    
    all_required_available = True
    
    for dep, available in dependencies_status.items():
        if available:
            version = get_package_version(dep)
            print(f"{GREEN}[OK]{RESET} {dep} ({version}) - {dep.title()} ready")
        else:
            print(f"{RED}[FAIL]{RESET} {dep} - Not installed")
            all_required_available = False
    
    return all_required_available


def generate_matrix_data() -> tuple:
    """Generate sample matrix data for analysis."""
    # Import numpy for matrix operations
    try:
        import numpy as np
    except ImportError:
        print("Error: numpy is required for matrix analysis")
        return None, None
    
    # Create sample "Matrix" data - transformation matrices
    mtx1 = np.array([[2, 1], [5, 2]])
    mtx2 = np.array([[1, 0], [0, 1]])
    
    return mtx1, mtx2


def analyze_matrix_data():
    """Analyze matrix data and perform operations."""
    try:
        import numpy as np
        import pandas as pd
    except ImportError:
        print("Error: numpy and pandas are required")
        return None
    
    print("Analyzing Matrix data...")
    
    # Generate sample data with 1000 points
    np.random.seed(42)
    data_points = 1000
    
    # Create simulated matrix transformation data
    x_data = np.linspace(0, 10, data_points)
    y_data = 2 * x_data + np.random.normal(0, 2, data_points)
    
    # Create DataFrame
    df = pd.DataFrame({
        'x': x_data,
        'y': y_data,
        'transformation': np.sin(x_data) * 10
    })
    
    print(f"Processing {data_points} data points...")
    print(f"Data shape: {df.shape}")
    print(f"Data statistics:")
    print(df.describe())
    
    return df, x_data, y_data


def generate_visualization(x_data, y_data):
    """Generate and save visualization of the data."""
    try:
        import matplotlib.pyplot as plt
    except ImportError:
        print("Error: matplotlib is required for visualization")
        return False
    
    print("Generating visualization...")
    
    plt.figure(figsize=(10, 6))
    plt.scatter(x_data, y_data, alpha=0.6, s=10, color='blue')
    plt.xlabel('X Values')
    plt.ylabel('Y Values (Transformed)')
    plt.title('Matrix Analysis - Data Transformation')
    plt.grid(True, alpha=0.3)
    
    output_file = 'matrix_analysis.png'
    plt.savefig(output_file, dpi=150, bbox_inches='tight')
    plt.close()
    
    return True, output_file


def main() -> None:
    """Main program execution."""
    # Check dependencies
    dependencies_status = check_dependencies()
    
    # Display loading status
    all_available = display_loading_status(dependencies_status)
    print()
    
    # Check if all required packages are available
    required_packages = ['pandas', 'numpy', 'matplotlib']
    missing_packages = [pkg for pkg in required_packages if not dependencies_status[pkg]]
    
    if missing_packages:
        print(f"\n{RED}ERROR: Missing required packages: {', '.join(missing_packages)}{RESET}")
        print("\nTo install dependencies:")
        print(f"  Using pip:   pip install -r requirements.txt")
        print(f"  Using Poetry: poetry install")
        return
    
    # Perform analysis
    print()
    df, x_data, y_data = analyze_matrix_data()
    
    if df is None:
        print("Failed to analyze data")
        return
    
    print()
    result = generate_visualization(x_data, y_data)
    
    if result:
        success, output_file = result
        if success:
            print(f"Analysis complete!")
            print(f"Results saved to: {output_file}")
    else:
        print("Failed to generate visualization")


if __name__ == "__main__":
    main()