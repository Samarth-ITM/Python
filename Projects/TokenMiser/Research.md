TokenMiser — Compiled System Specification
Purpose

TokenMiser is a prompt compiler and optimizer that transforms natural-language prompts into a structured DSL and minimizes token usage before sending them to an LLM such as Claude.

Target benefits:

50–80% prompt token reduction

reusable instructions and templates

reasoning budget control

structured prompt language

1. Core System Architecture

Instead of random function chains, treat the system like a compiler pipeline.

Pipeline:

User Prompt
↓
Context Gathering
↓
Prompt AST Builder
↓
Static Analysis
↓
Optimization Passes
↓
DSL Encoding
↓
Reasoning Budget Assignment
↓
Optional Chinese Compression
↓
Final Prompt Output

Each stage transforms the prompt.

2. Tech Stack

Your current stack is actually reasonable.

Runtime

Python

Jupyter Notebook (ipynb) for prototyping

Later move to a proper backend.

Model Layer

Primary analysis model:

Gemini Flash

Optional local lightweight model:

LLaMA 1B

Local models help with:

static analysis

prompt transformations

LLM Router

Library:

LiteLLM

Purpose:

unified API

switch models easily

cost tracking

Core Python Libraries

Recommended:

pydantic
dataclasses
tiktoken
numpy
rich (for CLI UI)

For caching:

redis (later)
sqlite (early prototype)
3. Data Structure Design

Stop passing messy text blobs between functions.

Define structured objects.

Example prompt object:

class PromptState:
    user_prompt: str
    context_data: dict
    static_analysis: dict
    compressed_prompt: str
    dsl_prompt: str
    reasoning_budget: int

Each stage updates this object.

4. Function Architecture

Your earlier idea becomes cleaner as modules.

Module 1 — Context Gathering

Purpose:

understand user intent

collect missing data

Flow:

User Prompt
↓
Gemini Flash
↓
Clarifying Questions
↓
User Response

Function:

def gather_context(prompt):
    questions = llm_analyze(prompt)
    answers = user_input()
    return context_object

Output:

structured task description
Module 2 — Prompt AST Builder

Convert prompt into structured representation.

Example:

TASK = library_system
LANG = python
STYLE = simple
OUTPUT = code

Internal structure:

PromptAST
 ├─ task
 ├─ language
 ├─ style
 └─ output

Function:

def build_prompt_ast(context):
    return ast
Module 3 — Static Analysis

Detect problems:

redundancy

contradictions

verbosity

unnecessary reasoning

Example result:

{
 "redundant_instructions": true,
 "compression_level": "medium",
 "recommended_templates": ["TMP_CODE_GEN"]
}

Function:

def static_analysis(ast):
    return analysis_report
Module 4 — Compression Pass

Rewrite instructions.

Example:

Before:

Write a simple Python program to manage a library system.

After:

TASK=LIBRARY_SYSTEM
LANG=PY
STYLE=SIMPLE

Function:

def compression_pass(ast):
    return compressed_prompt
Module 5 — Template Matching

Match task with template.

Example:

TMP_CODE_GEN

Template expands internally.

Function:

def apply_template(ast):
    return templated_prompt
Module 6 — DSL Encoding

Convert prompt into TokenMiser DSL.

Example:

TASK=LIB_SYS
LANG=PY
STYLE=SIMPLE
OUT=CODE

Function:

def encode_dsl(prompt):
    return dsl_prompt
Module 7 — Reasoning Budget

Allocate reasoning tokens.

Rules:

classification → 0
summarization → 50
coding → 200
architecture → 1000

Function:

def allocate_reasoning(task):
    return budget
Module 8 — Chinese Compression (Optional)

Compress static instructions.

Example:

代码简单
无注释

This step is optional.

Function:

def chinese_compression(dsl):
    return compressed_dsl
Module 9 — Prompt Validator

Final check.

Checklist:

✓ task defined
✓ output defined
✓ context references resolved
✓ reasoning budget assigned

Function:

def validate_prompt(prompt):
    return checklist
Module 10 — Final Output

User receives a copyable prompt.

Example:

TASK=LIB_SYS
LANG=PY
STYLE=SIMPLE
OUT=CODE
REASONING_POLICY=minimal
THINK_BUDGET=200
5. Sigil / Reference System

You want reusable instructions.

Correct design:

RULE_SIMPLE_CODE
RULE_NO_COMMENTS
RULE_BEGINNER_STYLE

Stored in a dictionary:

RULES = {
 "RULE_SIMPLE_CODE": "code simple readable structure",
 "RULE_NO_COMMENTS": "avoid comments in output"
}

Prompt:

RULE_SIMPLE_CODE
TASK=LIB_SYS
LANG=PY
6. Cache Layer

Two caches needed.

Prompt Cache

Store optimized prompts.

hash(prompt) → optimized_prompt
Semantic Cache

Use embeddings.

query → vector search → cached answer
7. Project File Structure
tokenmiser/
│
├── main.ipynb
├── config.py
├── models.py
├── pipeline/
│   ├── context.py
│   ├── ast_builder.py
│   ├── static_analysis.py
│   ├── compression.py
│   ├── templates.py
│   ├── dsl_encoder.py
│   ├── reasoning_budget.py
│   └── validator.py
│
├── rules/
│   ├── rule_library.py
│
└── cache/
    ├── prompt_cache.py
8. Implementation Order

Do not build everything at once.

Build in this order:

Phase 1 — Prototype

context gathering

compression pass

DSL encoder

Goal: working pipeline.

Phase 2 — Structure

prompt AST

static analysis

templates

Phase 3 — Efficiency

caching

reasoning budgets

cost estimator

Phase 4 — Advanced

sigil reference system

Chinese compression

prompt validator

9. Realistic Project Complexity

This is not a weekend notebook.

If implemented properly:

~2000–4000 lines of code

Still manageable.

10. Final System Pipeline
User Prompt
↓
Context Gathering
↓
Prompt AST
↓
Static Analysis
↓
Compression Pass
↓
Template Injection
↓
DSL Encoding
↓
Reasoning Budget Assignment
↓
Optional Chinese Compression
↓
Prompt Validation
↓
Final Optimized Prompt
Brutal Advice